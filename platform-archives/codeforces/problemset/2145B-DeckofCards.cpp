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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int a = count(all(s), '0');
    int b = count(all(s), '1');
    int c = count(all(s), '2');
    string res(n, '+');
    REP(i,n) {
      if (i < a+c || i >= n-b-c) res[i] = '?';
      if (i < a || i >= n-b || k == n) res[i] = '-';
    }
    cout << res << "\n";
  }

  return 0;
}
