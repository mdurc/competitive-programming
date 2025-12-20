struct Node {
  ll sum, pref;
  friend Node operator+(Node l, Node r) {
    return {l.sum + r.sum, max(l.pref, l.sum + r.pref)};
  }
  friend ostream& operator<<(ostream& os, const Node& n) {
    os << "{" << n.sum << ", " << n.pref << "}\n"; return os;
  }
};
struct SGT {
  int n;
  vector<ll> tree;
  SGT(vector<int>& a) {
    n = 1;
    while (n < (int)a.size()) n <<= 1; // hold 2 * next power of 2
    tree.assign(2 * n, 0LL);
    build(a);
    // for (int i = 0; i < (int)a.size(); ++i) change(1, 0, n-1, i, a[i]);
  }
  void build(vector<int>& a) {
    // root node is at 1, children as i*2 and i*2+1
    for (int i = 0; i < (int)a.size(); ++i) {
      tree[n + i] = a[i]; // fill in all the leaf nodes [n, 2*n-1]
    }
    for (int i = n - 1; i >= 1; --i) { // fill in parent nodes
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  // change(1, 0, n-1, idx:0-based, value)
  void change(int node, int node_lo, int node_hi, int idx, ll val) {
    if (node_lo == idx && node_hi == idx) { // leaf node
      tree[node] = val;
      return;
    }
    if (node_lo > idx || node_hi < idx) return;
    int end_low = node_lo + (node_hi - node_lo) / 2;
    change(2 * node, node_lo, end_low, idx, val);
    change(2 * node + 1, end_low + 1, node_hi, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  void change_iter(int idx, ll val) {
    tree[n + idx] = val;
    for (int i = (n + idx) / 2; i >= 1; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  ll query_driver(int l, int r) {
    return query(1, 0, n-1, l, r); // make sure l and r are 0-based
  }
  // query(1, 0, n-1, l, r) --> note that lo and hi are all 0-based
  ll query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
    if (query_lo <= node_lo && node_hi <= query_hi) {
      return tree[node]; // current node's sum
    }
    if (node_lo > query_hi || node_hi < query_lo) {
      return 0; // current node is disjoint in query range
    }
    // new range that the next nodes will encompass
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return query(2 * node, node_lo, end_low, query_lo, query_hi) +
           query(2 * node + 1, end_low + 1, node_hi, query_lo, query_hi);
  }
};
