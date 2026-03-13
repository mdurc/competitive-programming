class Solution {
public:
    void solve(vector<vector<char>>& board) {
      int n = (int)board.size(), m = (int)board[0].size();
      std::vector<std::vector<bool>> seen(n, std::vector<bool>(m, 0));
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto bfs = [&](int sr, int sc) -> void {
        std::set<std::pair<int,int>> region;
        std::queue<std::pair<int,int>> q;
        q.emplace(sr, sc);
        region.insert(std::make_pair(sr,sc));
        seen[sr][sc] = 1;
        bool ok = 1;
        while (!q.empty()) {
          std::pair<int,int> cur = q.front(); q.pop();
          auto [r, c] = cur;
          for (int i = 0; i < 4; ++i) {
            int nr = r+dr[i], nc = c+dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
              ok = 0;
              continue;
            }
            if (board[nr][nc] == 'O' && !seen[nr][nc]) {
              seen[nr][nc] = 1;
              region.insert(std::make_pair(nr,nc));
              q.emplace(nr, nc);
            }
          }
        }
        if (ok) {
          for (auto [r, c]: region) {
            board[r][c] = 'X';
          }
        }
      };
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (board[i][j] == 'O' && !seen[i][j]) {
            bfs(i, j);
          }
        }
      }
    }
};
