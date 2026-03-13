// multi-source bfs from each treasure node, O(m*n)
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
      int n = (int)grid.size(), m = (int)grid[0].size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
      std::queue<std::pair<int,int>> q;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 0) {
            q.emplace(i, j);
            dist[i][j] = 0;
          }
        }
      }
      while (!q.empty()) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
          std::pair<int,int> u = q.front(); q.pop();
          auto [r, c] = u;
          for (int j = 0; j < 4; ++j) {
            int nr = r+dr[j], nc = c+dc[j];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && dist[nr][nc] == -1) {
              dist[nr][nc] = dist[r][c] + 1;
              if (grid[nr][nc] == INT_MAX) grid[nr][nc] = dist[nr][nc];
              q.emplace(nr, nc);
            }
          }
        }
      }
    }
};

// bfs from each land node, O((m*n)^2)
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
      int n = (int)grid.size(), m = (int)grid[0].size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto bfs = [&](int sr, int sc) {
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        std::queue<std::pair<int,int>> q;
        dist[sr][sc] = 0;
        q.emplace(sr, sc);
        int res = INT_MAX;
        while (!q.empty()) {
          std::pair<int,int> u = q.front(); q.pop();
          auto [r, c] = u;
          for (int i = 0; i < 4; ++i) {
            int nr = r+dr[i], nc = c+dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && dist[nr][nc] == -1) {
              dist[nr][nc] = dist[r][c] + 1;
              if (grid[nr][nc] == 0) res = std::min(res, dist[nr][nc]);
              q.emplace(nr, nc);
            }
          }
        }
        return res;
      };
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == INT_MAX) {
            grid[i][j] = bfs(i, j);
          }
        }
      }
    }
};
