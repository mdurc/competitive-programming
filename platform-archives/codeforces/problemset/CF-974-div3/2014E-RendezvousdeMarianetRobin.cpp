#include <bits/stdc++.h>

using ll = long long;
const ll inf = 1e18;

std::vector<ll> dijk_1(int a, std::vector<std::vector<std::pair<int,int>>>& adj, std::vector<bool>& horse) {
  int n = (int)adj.size();
  std::vector<ll> dist(n * 2, inf);
  std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
  pq.emplace(0LL, a * 2);
  dist[a * 2] = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) {
      continue;
    }
    int x = u / 2;
    int has_horse = u % 2 == 1;
    if (!has_horse && horse[x]) {
      if (d < dist[x * 2 + 1]) {
        dist[x * 2 + 1] = d;
        pq.emplace(d, x * 2 + 1);
      }
    }
    for (auto [v, w] : adj[x]) {
      int nxt = v * 2 + has_horse;
      ll ndist = (has_horse ? w / 2 : w) + dist[u];
      if (ndist < dist[nxt]) {
        dist[nxt] = ndist;
        pq.emplace(ndist, nxt);
      }
    }
  }
  std::vector<ll> d(n);
  for (int i = 0; i < n; ++i) {
    d[i] = std::min(dist[i * 2], dist[i * 2 + 1]);
  }
  return d;
}

std::vector<ll> dijk_2(int a, std::vector<std::vector<std::pair<int,int>>>& adj, std::vector<bool>& horse) {
  int n = (int)adj.size();
  std::vector<ll> dist(n * 2, inf);
  std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
  pq.emplace(0LL, a * 2);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] != inf) continue;
    dist[u] = d;
    int x = u / 2;
    int has_horse = u % 2 == 1;
    if (!has_horse && horse[x]) {
      pq.emplace(d, x * 2 + 1);
    }
    for (auto [v, w] : adj[x]) {
      pq.emplace((has_horse ? w / 2 : w) + dist[u], v * 2 + has_horse);
    }
  }
  std::vector<ll> d(n);
  for (int i = 0; i < n; ++i) {
    d[i] = std::min(dist[i * 2], dist[i * 2 + 1]);
  }
  return d;
}

void solve() {
  int n, m, h;
  std::cin >> n >> m >> h;
  std::vector<bool> horse(n);
  for (int i = 0; i < h; ++i) {
    int a;
    std::cin >> a;
    horse[a - 1] = 1;
  }
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u - 1].emplace_back(v - 1, w);
    adj[v - 1].emplace_back(u - 1, w);
  }
  std::vector<ll> d1 = dijk_2(0, adj, horse);
  std::vector<ll> d2 = dijk_2(n - 1, adj, horse);
  ll res = inf;
  for (int i = 0; i < n; ++i) {
    res = std::min(res, std::max(d1[i], d2[i]));
  }
  if (res == inf) res = -1;
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
