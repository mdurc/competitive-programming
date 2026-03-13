class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      const int inf = 1e9;
      vector<int> dist(n, inf);
      dist[src] = 0;
      for (int i = 0; i <= k; ++i) {
        std::vector<int> tmp = dist; // ensures only one step per k
        for (std::vector<int>& e: flights) {
          int u = e[0], v = e[1], w = e[2];
          if (dist[u] != inf && dist[u]+w < tmp[v]) {
            tmp[v] = dist[u]+w;
          }
        }
        dist = tmp;
      }
      return dist[dst] == inf ? -1: dist[dst];
    }
};
