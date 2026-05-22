#include <bits/stdc++.h>

struct Node {
  long long sum;
  long long lazy;
  bool has_lazy;
  friend Node operator+(const Node& l, const Node& r) {
    return {l.sum + r.sum, 0, false};
  }
  friend std::ostream& operator<<(std::ostream& os, const Node& n) {
    os << "{" << n.sum << ", " << n.lazy << ", " << n.has_lazy << "}\n"; return os;
  }
};
struct SGT {
  int sz;
  std::vector<Node> tree;
  SGT(std::vector<int>& a) {
    sz = 1;
    while (sz < (int)a.size()) sz <<= 1;
    tree.assign(2 * sz, Node{0, 0, false});
    build(a);
  }
  void build(std::vector<int>& a) {
    for (int i = 0; i < (int)a.size(); ++i) tree[sz+i] = Node{a[i], 0, false};
    for (int i = sz-1; i >= 1; --i) tree[i] = tree[2*i] + tree[2*i+1];
  }
  // how a lazy-tag affects a node
  void apply(int node, int node_lo, int node_hi, long long lazy) {
    // for prefix-sum, adding lazy to each element increases total by lazy * count
    tree[node].sum += lazy * (node_hi-node_lo+1);
    tree[node].lazy += lazy; // accumulate tags for this child
    tree[node].has_lazy = true;
  }
  // push pending tags down to children
  void push(int node, int node_lo, int node_hi) {
    if (!tree[node].has_lazy || node_lo == node_hi) return;
    int end_low = node_lo + (node_hi - node_lo) / 2;
    apply(2 * node, node_lo, end_low, tree[node].lazy);
    apply(2 * node + 1, end_low + 1, node_hi, tree[node].lazy);
    tree[node].lazy = 0;
    tree[node].has_lazy = false;
  }
  // add 'val' to each element within [l,r]
  void update(int node, int node_lo, int node_hi, int l, int r, long long val) {
    if (l <= node_lo && node_hi <= r) {
      apply(node, node_lo, node_hi, val);
      return;
    }
    if (node_lo > r || node_hi < l) return;
    push(node, node_lo, node_hi);
    int end_low = node_lo + (node_hi - node_lo) / 2;
    update(2 * node, node_lo, end_low, l, r, val);
    update(2 * node + 1, end_low + 1, node_hi, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  // query(1, 0, sz-1, l, r) --> note that lo and hi are all 0-based
  Node query(int node, int node_lo, int node_hi, int l, int r) {
    if (l <= node_lo && node_hi <= r) {
      return tree[node]; // current node's sum
    }
    if (node_lo > r || node_hi < l) {
      return {0, 0, false}; // identity value for disjoint node
    }
    push(node, node_lo, node_hi);
    // new range that the next nodes will encompass
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return query(2 * node, node_lo, end_low, l, r) +
           query(2 * node + 1, end_low + 1, node_hi, l, r);
  }
};
