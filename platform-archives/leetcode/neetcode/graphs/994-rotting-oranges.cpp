class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      // multi-source bfs
      int n = (int)grid.size(), m = (int)grid[0].size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      // std::map<std::pair<int,int>,int> dist;
      std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
      std::queue<std::pair<int,int>> q;
      int cnt_fresh = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 1) ++cnt_fresh;
          if (grid[i][j] == 2) {
            q.emplace(i, j);
            dist[i][j] = 0;
          }
        }
      }
      int mxdist = 0;
      while (cnt_fresh > 0 && !q.empty()) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
          std::pair<int,int> cur = q.front();
          auto [r, c] = cur;
          q.pop();
          for (int j = 0; j < 4; ++j) {
            int nr = r+dr[j], nc = c+dc[j];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && dist[nr][nc] == -1) {
              dist[nr][nc] = dist[r][c]+1;
              mxdist = std::max(mxdist, dist[nr][nc]);
              q.emplace(nr, nc);
              --cnt_fresh;
            }
          }
        }
      }
      return cnt_fresh == 0 ? mxdist : -1;
    }
};
