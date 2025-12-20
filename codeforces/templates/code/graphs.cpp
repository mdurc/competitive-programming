const ll INF = 1e18;
const int MAX_N = 1e5 + 10;
const int MAX_LOG = 20;
int n;
vector<pi> adj_w[MAX_N]; // weighted: {neighbor, weight}
vector<int> adj[MAX_N];  // unweighted

// tree algorithms
int up[MAX_N][MAX_LOG];
int depth[MAX_N];
bool visited[MAX_N];

int timer = 0;
int previsit[MAX_N];
int postvisit[MAX_N];

vector<int> bfs(int start) {
  vector<int> dist(n + 1, -1);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int b : adj[a]) {
      if (dist[b] == -1) {
        dist[b] = dist[a] + 1;
        q.push(b);
      }
    }
  }
  return dist;
}

void bfs_dirs() {
  vector<pi> dirs({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
  queue<pi> q;
  q.push({0, 0});
  while (!q.empty()) {
    pi pos = q.front();
    q.pop();
    for (pi dir : dirs) {
      int ni = pos.first + dir.first;
      int nj = pos.second + dir.second;
    }
  }
}

void dfs(int a) {
  visited[a] = true;
  previsit[a] = timer++;
  for (int b : adj[a]) {
    if (!visited[b]) {
      depth[b] = depth[a] + 1;
      // for undirected, check that (b != up[a][0])
      up[b][0] = a;
      dfs(b);
    }
  }
  postvisit[a] = timer++;
}

vector<ll> dijkstra(int start) {
  vector<ll> dist(n + 1, INF);
  priority_queue<pi, vector<pi>, greater<pi>> pq; // min heap
  dist[start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    auto [d, a] = pq.top();
    pq.pop();
    if (d > dist[a]) continue;
    for (auto [b, w] : adj_w[a]) {
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w;
        pq.push({dist[b], b});
      }
    }
  }
  return dist;
}

vector<ll> bellman_ford(int start) {
  vector<ll> dist(n + 1, INF);
  dist[start] = 0;
  for (int i = 1; i < n; i++) {
    for (int a = 1; a <= n; a++) {
      if (dist[a] == INF) continue;
      for (auto [b, w] : adj_w[a]) {
        if (dist[b] > dist[a] + w) {
          dist[b] = dist[a] + w;
        }
      }
    }
  }
  for (int a = 1; a <= n; a++) { // check for negative cycles
    if (dist[a] == INF) continue;
    for (auto [b, w] : adj_w[a]) {
      if (dist[b] > dist[a] + w) {
        dist[b] = -INF; // mark as affected by negative cycle
      }
    }
  }
  return dist;
}

vector<vector<ll>> floyd_warshall() {
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0; // self distances
    for (auto [b, w] : adj_w[i]) {
      dist[i][b] = min(dist[i][b], (ll)w); // direct edges
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] < INF && dist[k][j] < INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  return dist;
}

vector<int> topological_sort() {
  vector<int> in_degree(n + 1, 0);
  for (int a = 1; a <= n; a++) {
    for (int b : adj[a]) {
      in_degree[b]++;
    }
  }

  queue<int> q;
  for (int a = 1; a <= n; a++) {
    if (in_degree[a] == 0) q.push(a);
  }

  vector<int> topo;
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    topo.push_back(a);
    for (int b : adj[a]) {
      in_degree[b]--;
      if (in_degree[b] == 0) q.push(b);
    }
  }

  if (topo.size() != n) return {}; // cycle exists
  return topo;
}

// implies that there are no odd-length cycles
bool is_bipartite() {
  vector<int> group(n, -1);
  for (int i = 0; i < n; ++i) {
    if (group[i] != -1) continue;
    // bfs from this cc
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (int b : adj[a]) {
        if (group[b] == -1) {
          group[b] = 1 - group[a];
          q.push(b);
        } else if (group[b] == group[a]) {
          return false;
        }
      }
    }
  }
  return true;
}
