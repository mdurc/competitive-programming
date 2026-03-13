#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> ps(n);
    partial_sum(a.begin(), a.end(), ps.begin());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        int sum = ps[j] - (i > 0 ? ps[i - 1] : 0);
        ans = max(ans, sum / (j - i + 1));
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
