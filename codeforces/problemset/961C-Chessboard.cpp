#include <bits/stdc++.h>
#include <algorithm>
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

int set_board(vector<string>& cur, char corner) {
  char other = corner == '1' ? '0' : '1';
  int res = 0, n = cur.size();
  REP(i,n) {
    REP(j,n) {
      if (i % 2 == 1) {
        if (j % 2 == 1 && cur[i][j] != corner) ++res;
        else if (j % 2 == 0 && cur[i][j] != other) ++res;
      } else {
        if (j % 2 == 1 && cur[i][j] != other) ++res;
        else if (j % 2 == 0 && cur[i][j] != corner) ++res;
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<string>> b(4);
  REP(t,4) {
    vector<string> cur(n);
    REP(i,n) {
      cin >> cur[i];
    }
    b[t] = cur;
  }

  int res = INT_MAX;
  int perm[4];
  iota(perm,perm+4,0);
  do {
    int sum = 0;
    sum += set_board(b[perm[0]], '1');
    sum += set_board(b[perm[1]], '1');
    sum += set_board(b[perm[2]], '0');
    sum += set_board(b[perm[3]], '0');
    res = min(res, sum);
  } while(next_permutation(perm,perm+4));

  cout << res << "\n";

  return 0;
}
