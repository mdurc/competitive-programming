// Assumes 1-based node indexing
const ll inf = 1e18;
const int mxn = 1e5 + 10;
const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
vector<int> adj[mxn];
vector<pair<int, int>> adj_w[mxn]; // weighted: {node, wt}
vector<vector<int>> edges; // edge list: {u, v, w}

vector<int> bfs(int start) {
  vector<int> dist(n + 1, -1);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist;
}

int depth[mxn];
bool seen[mxn];
int up[mxn][20];
void dfs(int u) {
  seen[u] = true;
  for (int v : adj[u]) {
    if (!seen[v]) {
      depth[v] = depth[u] + 1;
      up[v][0] = u;
      dfs(v);
    }
  }
}

// O(E log V), single source, non-negative edge weights
vector<ll> dijkstra(int start) {
  vector<ll> dist(n + 1, inf);
  priority_queue<pi, vector<pi>, greater<pi>> pq; // min heap
  dist[start] = 0;
  pq.emplace(0, start);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : adj_w[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
    }
  }
  return dist;
}

// O(V * E), single source, handles negative edges/cycles
vector<ll> bellman_ford(int start) {
  vector<ll> dist(n + 1, inf);
  dist[start] = 0;
  // update from all edges, n-1 times
  for (int i = 0; i < n-1; i++) {
    /*
    // with adjacency list:
    for (int u = 1; u <= n; u++) {
      if (dist[u] == inf) continue;
      for (auto [v, w] : adj_w[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
        }
      }
    }
    */
    // with list of edges:
    for (std::vector<int>& e: edges) {
      int u = e[0], v = e[1], w = e[2];
      if (dist[u] != inf && dist[u]+w < dist[v]) {
        dist[v] = dist[u]+w;
      }
    }
  }
  // OPTIONAL: detect and mark negative cycles, run one more cycle of inner block above
  // if it is optimal to update dist[v], then set dist[v] = -inf.
  return dist;
}

// O(V^3), all-pairs shortest path, small graph sizes (V <= 400)
vector<vector<ll>> floyd_warshall() {
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
  for (int i = 1; i <= n; i++) dist[i][i] = 0; // main diagonal (self distances)

  /*
  // from adjacency matrix:
  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : adj_w[u]) {
      dist[u][v] = w; // direct edge weight is smallest
      // dist[u][v] = min(dist[u][v], (ll)w); // for multiple edges to the same node
    }
  }
  */

  // from edge list
  for (std::vector<int>& e: edges) {
    dist[e[0]][e[1]] = e[2];
    // dist[e[0]][e[1]] = min(dist[e[0]][e[1]], (ll)e[2]); // for multiple edges to the same node
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] < inf && dist[k][j] < inf) { // prevent overflow
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  return dist;
}

// nodes in decreasing post-order visit
vector<int> topological_sort() {
  vector<int> in_degree(n + 1, 0);
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      in_degree[v]++;
    }
  }
  queue<int> q;
  for (int u = 1; u <= n; u++) {
    if (in_degree[u] == 0) q.push(u);
  }
  vector<int> topo;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (int v : adj[u]) {
      in_degree[v]--;
      if (in_degree[v] == 0) q.push(v);
    }
  }

  if (topo.size() != n) return {}; // cycle exists
  return topo;
}

// implies that there are no odd-length cycles
bool is_bipartite() {
  vector<int> group(n+1, -1);
  for (int i = 1; i <= n; ++i) {
    if (group[i] != -1) continue;
    // bfs from this connected component
    queue<int> q;
    q.push(i);
    group[i] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (group[v] == -1) {
          group[v] = 1 - group[u];
          q.push(v);
        } else if (group[v] == group[u]) {
          return false;
        }
      }
    }
  }
  return true;
}

// -- More complex structures and algorithms --

struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    return true;
  }
};

// -------Minimum spanning tree-------
// returns MST weight, -1 if graph is disconnected
bool seen[mxn];
ll prim(int start) {
  ll cost = 0, node_cnt = 0;
  priority_queue<pi, vector<pi>, greater<pi>> pq; // min heap
  pq.emplace(0, start);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (!seen[u]) {
      seen[u] = true;
      cost += d, node_cnt++;
      for (auto [v, w]: adj_w[u]) {
        if (!seen[v]) {
          pq.emplace(w, v);
        }
      }
    }
  }
  return node_cnt != n ? -1: cost;
}
ll kruskal() {
  // sort edges by weight
  sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[2] < b[2];
      });
  ll cost = 0;
  int edge_cnt = 0;
  DSU dsu(n);
  for (const vector<int>& e: edges) {
    if (dsu.merge(e[0], e[1])) {
      cost += e[2];
      edge_cnt++;
    }
  }
  if (edge_cnt < n - 1) return -1;
  return cost;
}
// -----------------------------------

// -- Strongly Connected Components --
vector<int> order; // post-order visit, stack
vector<int> component; // current SCC
vector<int> adj[mxn];
bool seen[mxn];
// find decreasing post-order visit number. Last post-order visit is in a source SCC.
void dfs1(int u) {
  seen[u] = true;
  for (int v : adj[u]) {
    if (!seen[v]) dfs1(v);
  }
  order.push_back(u);
}
void dfs2(int u) { // on reverse graph, starting at source SCC node
  seen[u] = true;
  component.push_back(u);
  for (int v : adj_rev[u]) {
    if (!seen[v]) dfs2(v);
  }
}
vector<vector<int>> kosaraju() {
  // build reverse graph
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      adj_rev[v].push_back(u);
    }
  }
  memset(seen, 0, sizeof(seen));
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) dfs1(i);
  }
  memset(seen, 0, sizeof(seen));
  reverse(order.begin(), order.end());
  vector<vector<int>> sccs;
  for (int u : order) {
    if (!seen[u]) {
      component.clear();
      dfs2(u);
      sccs.push_back(component);
    }
  }
  return sccs;
}
// -----------------------------------
