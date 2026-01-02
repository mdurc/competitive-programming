#include <bits/stdc++.h>

const int mxn = 1005;
const int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
std::queue<std::pair<int,int>> q[9];
int cnt[mxn];
int d[mxn][mxn];

void solve() {
  int n, m, p;
  std::cin >> n >> m >> p;
  std::vector<int> s(p);
  for (int i = 0; i < p; ++i) std::cin >> s[i];
  for (int i = 0; i < n; ++i) {
    std::string row;
    std::cin >> row;
    for (int j = 0; j < m; ++j) {
      if (row[j] >= '1' && row[j] <= '9') {
        q[row[j]-'1'].push(std::make_pair(i,j));
        ++cnt[row[j]-'1'];
      } else if (row[j] == '.') {
        d[i][j] = -1;
      } else {
        d[i][j] = 1;
      }
    }
  }
  long long turn = 0;
  while (1) {
    bool rem = 0;
    for (int i = 0; i < p; ++i) {
      while (!q[i].empty()) {
        int x = q[i].front().first, y = q[i].front().second;
        if (d[x][y] >= turn * s[i]) break;
        q[i].pop();
        for (int j = 0; j < 4; ++j) {
          int r = x + dr[j];
          int c = y + dc[j];
          if (r < 0 || r >= n || c < 0 || c >= m || d[r][c] != -1) {
            continue;
          }
          d[r][c] = d[x][y] + 1;
          q[i].push(std::make_pair(r,c));
          ++cnt[i];
        }
      }
      if (!q[i].empty()) rem = 1;
    }
    if (!rem) break;
    ++turn;
  }
  for (int i = 0; i < p; ++i) {
    std::cout << cnt[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
