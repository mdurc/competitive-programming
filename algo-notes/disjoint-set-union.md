## Disjoint Set Union (DSU)

> **TL;DR:** Tracks connected components in a forest/graph and allows fast merging of sets/subtrees.

### 1. Structure and Implementation Optimizations

* **Problem:** If you use an array to track which component each node belongs to, checking if two nodes are connected is $O(1)$, but merging two components requires an $O(N)$ sweep to update the IDs. If you use standard DFS/BFS to check connectivity, each query is $O(N)$.
* **Insight:** Instead of flattening the components, represent them as a collection of trees. Each node points to a "parent". The root of the tree is the "representative" of the component.
* **Optimizations:**
  1. **Path Compression:** When you walk up the tree to find the root, redirect every node on that path to point directly to the root. This flattens the tree dynamically.
  2. **Union by Size:** When merging two roots, always attach the smaller tree to the root of the larger tree. This guarantees the tree depth never exceeds $\log N$.

* **Usage:** this data structure is used to create the forest in Kruskals MST algorithm.

```cpp
const int mxn = 2e5 + 5;
int parent[mxn];
int sz[mxn];
void init(int n) {
  std::iota(parent, parent+n, 0);
  std::fill(sz, sz+n, 1);
}
int find(int u) {
  if (u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}
bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  if (sz[u] < sz[v]) std::swap(u, v);
  parent[v] = u;
  sz[u] += sz[v];
  return true;
}
```
