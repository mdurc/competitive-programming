// bfs from every position and check if we leave into both oceans, O((n*m)^2), still passes
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int n = (int)heights.size(), m = (int)heights[0].size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
      auto bfs = [&](int sr, int sc) -> bool {
        // resetting the dist array instead of re-initializing new memory is much faster and less memory intensive
        for (std::vector<int>& row: dist) std::fill(row.begin(), row.end(), -1);
        std::queue<std::pair<int,int>> q;
        q.emplace(sr, sc);
        dist[sr][sc] = 0;
        bool pac = 0, atl = 0;
        while (!q.empty()) {
          std::pair<int,int> cur = q.front(); q.pop();
          auto [r, c] = cur;
          for (int i = 0; i < 4; ++i) {
            int nr = r+dr[i], nc = c+dc[i];
            if (nr < 0 || nc < 0) pac = 1;
            if (nr >= n || nc >= m) atl = 1;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && heights[nr][nc] <= heights[r][c] && dist[nr][nc] == -1) {
              dist[nr][nc] = dist[r][c] + 1;
              q.emplace(nr, nc);
            }
          }
        }
        return pac && atl;
      };
      std::vector<std::vector<int>> res;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (bfs(i, j)) {
            res.push_back({i, j});
          }
        }
      }
      return res;
    }
};


// reverse BFS from both ocean edges to move inland as far as they can, O(n*m)
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int n = (int)heights.size(), m = (int)heights[0].size();
      std::vector<std::vector<bool>> pac(n, std::vector<bool>(m, 0));
      std::vector<std::vector<bool>> atl(n, std::vector<bool>(m, 0));
      std::queue<std::pair<int,int>> q_pac, q_atl;
      for (int i = 0; i < n; ++i) {
        q_pac.emplace(i, 0);
        pac[i][0] = true;
        q_atl.emplace(i, m - 1);
        atl[i][m - 1] = true;
      }
      for (int j = 0; j < m; ++j) {
        q_pac.emplace(0, j);
        pac[0][j] = true;
        q_atl.emplace(n - 1, j);
        atl[n - 1][j] = true;
      }
      int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto bfs = [&](std::queue<std::pair<int,int>>& q, std::vector<std::vector<bool>>& visited) {
        while (!q.empty()) {
          auto [r, c] = q.front();
          q.pop();
          for (int i = 0; i < 4; ++i) {
            int nr = r+dr[i], nc = c+dc[i];
            // move uphill because we are in reverse
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
              visited[nr][nc] = true;
              q.emplace(nr, nc);
            }
          }
        }
      };
      bfs(q_pac, pac);
      bfs(q_atl, atl);
      std::vector<std::vector<int>> res;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (pac[i][j] && atl[i][j]) {
            res.push_back({i, j});
          }
        }
      }
      return res;
    }
};
