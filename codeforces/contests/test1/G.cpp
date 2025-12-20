#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;

  if (n > k * k) {
    cout << "Impossible\n";
    return 0;
  }

  cout << "Possible\n";
  vector<int> ans;
  for (int i = 1; i <= n; i += k) {
    int R = min(i + k - 1, n);
    for (int j = R; j >= i; --j) {
      ans.push_back(j);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
