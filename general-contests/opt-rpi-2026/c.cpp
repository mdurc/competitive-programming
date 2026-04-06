#include <bits/stdc++.h>

const int inf = 2e9;
const int mxn = 5005;
int dist[mxn];
bool seen[mxn];

void solve() {
  double ws, js;
  int n;
  std::cin >> ws >> js >> n;
  std::vector<std::array<double,2>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i][0] >> a[i][1];
  }

  std::fill(dist, dist + n, inf);
  std::fill(seen, seen + n, 0);
  std::deque<int> q;
  dist[0] = 0;
  q.push_front(0);
  while (!q.empty()) {
    int u = q.front(); q.pop_front();
    if (seen[u]) continue;
    seen[u] = 1;
    for (int v = 0; v < n; ++v) {
      if (seen[v]) continue;
      double x = a[u][0]-a[v][0], y = a[u][1]-a[v][1];
      double d = x*x + y*y;
      if (d <= ws*ws) {
        if (dist[u] < dist[v]) {
          dist[v] = dist[u];
          q.push_front(v);
        }
      } else if (d <= js*js) {
        if (dist[u]+1 < dist[v]) {
          dist[v] = dist[u]+1;
          q.push_back(v);
        }
      }
    }
  }
  int ans = dist[n-1] == inf ? -1: dist[n-1];
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
