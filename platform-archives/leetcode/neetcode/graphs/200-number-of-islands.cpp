// O(n * m) with extra memory for tracking visited, intuitive, still passes
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int n = (int)grid.size(), m = (int)grid[0].size();
      std::vector<std::vector<bool>> seen(n, std::vector<bool>(m, 0));
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto dfs = [&](auto&& dfs, int r, int c) -> void {
        seen[r][c] = 1;
        for (int i = 0; i < 4; ++i) {
          int nr = r+dr[i], nc = c+dc[i];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !seen[nr][nc]) {
            dfs(dfs,nr,nc);
          }
        }
      };
      int res = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == '1' && !seen[i][j]) {
            ++res;
            dfs(dfs,i,j);
          }
        }
      }
      return res;
    }
};


// O(n * m) in place update of grid to mark as seen
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int n = (int)grid.size(), m = (int)grid[0].size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      auto dfs = [&](auto&& dfs, int r, int c) -> void {
        grid[r][c] = '0';
        for (int i = 0; i < 4; ++i) {
          int nr = r+dr[i], nc = c+dc[i];
          if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') {
            dfs(dfs,nr,nc);
          }
        }
      };
      int res = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == '1') {
            ++res;
            dfs(dfs,i,j);
          }
        }
      }
      return res;
    }
};
