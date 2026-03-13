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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    ll cur = n, res = 0, sum = 0;
    while (cur > m) {
      if (a[cur] < b[cur]) {
        res += sum + a[cur];
        sum = 0;
      } else {
        sum += b[cur];
      }
      --cur;
    }
    ll ans = 1e18;
    for (int i = m; i >= 1; --i) {
      ans = min(ans, res + sum + a[i]);
      sum += b[i];
    }
    cout << ans << "\n";
  }

  return 0;
}
