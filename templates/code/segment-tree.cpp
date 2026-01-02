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
  int sz; // holds next power of 2 after mxn of array
  vector<ll> tree;
  SGT(vector<int>& a) {
    sz = 1;
    while (sz < (int)a.size()) sz <<= 1;
    tree.assign(2 * sz, 0LL); // 2 * next power of 2, for children
    build(a);
    // for (int i = 0; i < (int)a.size(); ++i) change(1, 0, sz-1, i, a[i]);
  }
  void build(vector<int>& a) {
    // root node is at 1, children as i*2 and i*2+1
    for (int i = 0; i < (int)a.size(); ++i) {
      tree[sz + i] = a[i]; // fill in all the leaf nodes [sz, 2*sz-1]
    }
    for (int i = sz - 1; i >= 1; --i) { // fill in parent nodes
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  // change(1, 0, sz-1, idx:0-based, value)
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
    tree[sz + idx] = val;
    for (int i = (sz + idx) / 2; i >= 1; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  ll query_driver(int l, int r) {
    return query(1, 0, sz-1, l, r); // make sure l and r are 0-based
  }
  // query(1, 0, sz-1, l, r) --> note that lo and hi are all 0-based
  ll query(int node, int node_lo, int node_hi, int l, int r) {
    if (l <= node_lo && node_hi <= r) {
      return tree[node]; // current node's sum
    }
    if (node_lo > r || node_hi < l) {
      return 0; // current node is disjoint in query range
    }
    // new range that the next nodes will encompass
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return query(2 * node, node_lo, end_low, l, r) +
           query(2 * node + 1, end_low + 1, node_hi, l, r);
  }
};
