#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    // remove all until increasing
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i-1]) {
        ++res;
        a[i] = a[i-1];
      }
    }
    cout << res << "\n";
  }

  return 0;
}
