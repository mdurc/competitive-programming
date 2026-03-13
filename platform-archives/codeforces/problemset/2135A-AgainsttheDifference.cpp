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
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORD(i, a, b) for(int i=(a);i>=(b);--i)
#define REP(i, n) FOR(i,0,n)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n+1);
    FORE(i,1,n) cin >> a[i];

    vector<int> dp(n+1);
    map<int, queue<int>> m;
    dp[0] = 0;
    FORE(i,1,n) {
      m[a[i]].push(i);
      if (m[a[i]].size() > a[i]) m[a[i]].pop();
      dp[i] = dp[i-1];
      if (m[a[i]].size() == a[i]) {
        // check with the earliest starting pos of this value
        dp[i] = max(dp[i], dp[m[a[i]].front()-1]+a[i]);
      }
    }
    cout << dp[n] << "\n";
  }

  return 0;
}
