struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
};

struct Prim {
  struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
    bool operator<(const Edge& e) const {
      return weight > e.weight; // min-heap
    }
  };
  int n;
  vector<vector<Edge>> adj;
  vector<bool> visited;
  Prim(int _n) : n(_n) {
    adj.assign(n + 1, vector<Edge>());
    visited.assign(n + 1, false);
  }
  void add_edge(int u, int v, int w, bool directed = false) {
    adj[u].push_back(Edge(v, w));
    if (!directed) adj[v].push_back(Edge(u, w));
  }
  ll mst_cost(int root = 1) {
    ll cost = 0;
    priority_queue<Edge> pq;
    pq.push(Edge(root, 0));
    while (!pq.empty()) {
      Edge e = pq.top();
      pq.pop();
      int u = e.to;
      if (visited[u]) continue;
      visited[u] = true;
      cost += e.weight;
      for (Edge& next : adj[u])
        if (!visited[next.to]) pq.push(next);
    }
    return cost;
  }
};
