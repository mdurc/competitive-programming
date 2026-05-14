#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
#define sz(a) ((int)a.size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i=(a);i>=(b);--i)
#define REP(i, n) FOR(i,0,n)

int adj[19][19] = {0};
int checked[1 << 19][19] = {0};
ll cnt[1 << 19][19] = {0};
int n, m;

ll solve(int mask, int curr, int start) {
  if (checked[mask][curr] == start + 1) return cnt[mask][curr];
  ll res = 0;
  for (int i = start; i < n; ++i) {
    if (!adj[curr][i]) continue;
    if (i == start) {
      // need at least 3 nodes in the mask
      if (mask != ((1 << start) + (1 << curr))) ++res;
    } else {
      if (mask & (1 << i)) continue; // already visited
      res += solve(mask + (1 << i), i, start);
    }
  }
  checked[mask][curr] = start + 1;
  cnt[mask][curr] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    adj[a - 1][b - 1] = 1;
    adj[b - 1][a - 1] = 1;
  }
  ll res = 0;
  REP(i, n) res += solve(1 << i, i, i);
  cout << res / 2 << endl;
  return 0;
}
