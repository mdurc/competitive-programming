#include <bits/stdc++.h>

const int mxn = 101;
std::vector<std::pair<int,int>> adj[mxn];

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, y;
    std::cin >> u >> v >> y;
    adj[u].emplace_back(v, y);
    adj[v].emplace_back(u, y);
  }

  std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> q;
  q.emplace(0, 1);
  std::vector<long long> dist(n+1, -1);
  std::vector<int> order;
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (dist[u] != -1) continue;
    dist[u] = d;
    order.push_back(u);
    if (u == n) break;
    for (auto [v, w] : adj[u]) {
      if (dist[v] == -1) {
        q.emplace(d + w, v);
      }
    }
  }

  if (dist[n] == -1) {
    std::cout << "inf\n";
    return;
  }

  std::cout << dist[n] << " " << order.size()-1 << "\n";
  for (int i = 1; i < (int)order.size(); ++i) {
    std::string s(n, '0');
    for (int j = 0; j < i; ++j) {
      s[order[j]-1] = '1';
    }
    std::cout << s << " " << dist[order[i]] - dist[order[i-1]] << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
