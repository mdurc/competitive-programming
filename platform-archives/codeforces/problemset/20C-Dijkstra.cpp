#include <bits/stdc++.h>

using ll = long long;
const ll inf = 1e18;

std::pair<std::vector<ll>, std::vector<int>> dijk_1(int n, std::vector<std::vector<std::pair<int, int>>>& adj) {
  std::priority_queue<std::tuple<ll, int, int>, std::vector<std::tuple<ll, int, int>>, std::greater<>> pq;
  std::vector<ll> dist(n, inf);
  std::vector<int> parent(n, -1);
  pq.emplace(0LL, 0, -1);
  while (!pq.empty()) {
    auto [d, u, prev] = pq.top();
    pq.pop();
    if (dist[u] != inf) continue;
    dist[u] = d;
    parent[u] = prev;
    for (auto [v, w] : adj[u]) {
      pq.emplace(w + d, v, u);
    }
  }
  return std::make_pair(dist, parent);
}

std::pair<std::vector<ll>, std::vector<int>> dijk_2(int n, std::vector<std::vector<std::pair<int, int>>>& adj) {
  std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
  std::vector<ll> dist(n, inf);
  std::vector<int> parent(n, -1);
  dist[0] = 0;
  pq.emplace(0LL, 0);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.emplace(dist[v], v);
      }
    }
  }
  return std::make_pair(dist, parent);
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    std::cin >> a >> b >> w;
    adj[a - 1].emplace_back(b - 1, w);
    adj[b - 1].emplace_back(a - 1, w);
  }
  auto [dist, parent] = dijk_2(n, adj);
  if (dist[n - 1] == inf) {
    std::cout << "-1\n";
    return;
  }
  std::vector<int> res;
  for (int i = n - 1; i != -1; i = parent[i]) {
    res.push_back(i);
  }
  std::reverse(res.begin(), res.end());
  for (int i : res) {
    std::cout << i + 1 << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
