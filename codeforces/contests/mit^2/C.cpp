#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> pos(n+1);
    for (int i = 1; i <= n; ++i ){
      cin >> a[i];
      pos[a[i]] = i;
    }

    vector<int> visit(n+1, -1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (j != visit[a[i]] && j != visit[pos[i]]) {
          visit[i] = j;
          break;
        }
      }
    }
    char m[3] = {'R', 'G', 'B'};
    string res = "";
    for (int i = 1; i <= n; ++i) {
      res += m[visit[i]];
    }
    cout << res << "\n";
  }
}
