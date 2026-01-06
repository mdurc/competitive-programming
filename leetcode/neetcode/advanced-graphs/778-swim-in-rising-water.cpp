class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      // dijkstra with tracking largest value in path as the "dist"
      int n = (int)grid.size();
      const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
      const int inf = 2e9;
      std::vector<int> dist(n*n, inf);
      std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> pq;
      pq.emplace(grid[0][0], 0);
      dist[0] = grid[0][0];
      while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        int r = u/n, c = u%n;
        for (int i = 0; i < 4; ++i) {
          int nr = r+dr[i], nc = c+dc[i];
          int v = nr*n+nc;
          if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            int nxt = std::max(dist[u], grid[nr][nc]);
            if (nxt < dist[v]) {
              dist[v] = nxt;
              pq.emplace(dist[v], v);
            }
          }
        }
      }
      return dist[n*n-1];
    }
};
