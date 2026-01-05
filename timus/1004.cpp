#include <bits/stdc++.h>

using ll = long long;
const int inf = 1e8;

void solve(int n) {
  int m;
  std::cin >> m;
  std::vector<std::vector<int>> adj(n, std::vector<int>(n, inf));
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, inf));
  std::vector<std::vector<int>> p(n, std::vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    adj[i][i] = 0, dist[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u, --v;
    if (w < adj[u][v]) {
      adj[u][v] = adj[v][u] = w;
      dist[u][v] = dist[v][u] = w;
      p[u][v] = u, p[v][u] = v;
    }
  }
  int min_cycle = inf;
  std::vector<int> res;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < k; ++i) {
      for (int j = i + 1; j < k; ++j) {
        ll current_cycle = (ll)dist[i][j]+adj[i][k]+adj[j][k];
        if (current_cycle < min_cycle) {
          min_cycle = current_cycle;
          res.clear();
          res.push_back(k);
          int curr = j;
          while (curr != i) {
            res.push_back(curr);
            curr = p[i][curr];
          }
          res.push_back(i);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          p[i][j] = p[k][j];
        }
      }
    }
  }

  if (min_cycle == inf) {
    std::cout << "No solution.\n";
  } else {
    for (int i: res) {
      std::cout << i+1 << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  while (std::cin >> n) {
    if (n == -1) break;
    solve(n);
  }

  return 0;
}
