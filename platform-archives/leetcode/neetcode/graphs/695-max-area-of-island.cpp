// O(n * m) with extra memory for tracking visited, intuitive, still passes
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n = (int)grid.size(), m = (int)grid[0].size();
      std::vector<std::vector<bool>> seen(n, std::vector<bool>(m, 0));
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto dfs = [&](auto&& dfs, int r, int c) -> int {
        seen[r][c] = 1;
        int res = 1;
        for (int i = 0; i < 4; ++i) {
          int nr = r+dr[i], nc = c+dc[i];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] && !seen[nr][nc]) {
            res += dfs(dfs,nr,nc);
          }
        }
        return res;
      };
      int res = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] && !seen[i][j]) {
            res = std::max(res, dfs(dfs,i,j));
          }
        }
      }
      return res;
    }
};

// O(n * m) in place update of grid to mark as seen
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n = (int)grid.size(), m = (int)grid[0].size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto dfs = [&](auto&& dfs, int r, int c) -> int {
        grid[r][c] = 0;
        int res = 1;
        for (int i = 0; i < 4; ++i) {
          int nr = r+dr[i], nc = c+dc[i];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]) {
            res += dfs(dfs,nr,nc);
          }
        }
        return res;
      };
      int res = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j]) {
            res = std::max(res, dfs(dfs,i,j));
          }
        }
      }
      return res;
    }
};
