#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define REP(i, a, b) for(int i=(a);i<(b);++i)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int res = 0;
    REP(i,0,n) {
      int h;
      cin >> h;
      int diff = abs(H-h);
      if (diff == 0 || diff % k != 0) continue;
      if (diff/k < m) ++res;
    }
    cout << res << "\n";
  }

  return 0;
}
