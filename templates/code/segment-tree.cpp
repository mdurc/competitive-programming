#include <bits/stdc++.h>

struct Node {
  long long sum, pref;
  friend Node operator+(Node l, Node r) {
    return {l.sum + r.sum, std::max(l.pref, l.sum + r.pref)};
  }
  friend std::ostream& operator<<(std::ostream& os, const Node& n) {
    os << "{" << n.sum << ", " << n.pref << "}\n"; return os;
  }
};
struct SGT {
  int sz; // holds next power of 2 after mxn of array
  std::vector<long long> tree;
  SGT(std::vector<int>& a) {
    sz = 1;
    while (sz < (int)a.size()) sz <<= 1;
    tree.assign(2 * sz, 0LL); // 2 * next power of 2, for children
    build(a);
    // for (int i = 0; i < (int)a.size(); ++i) change(1, 0, sz-1, i, a[i]);
  }
  void build(std::vector<int>& a) {
    // fill in leaf nodes [sz,2*sz-1] then parent nodes [1..sz-1]
    for (int i = 0; i < (int)a.size(); ++i) tree[sz+i] = a[i];
    for (int i = sz-1; i >= 1; --i) tree[i] = tree[2*i] + tree[2*i+1];
  }
  void change(int idx, long long val) { // iterative
    tree[sz + idx] = val;
    for (int i = (sz + idx) / 2; i >= 1; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  // change(1, 0, sz-1, idx:0-based, value)
  void change(int node, int node_lo, int node_hi, int idx, long long val) {
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
  long long query(int l, int r) { // iterative (much simpler to write)
    long long res = 0;
    for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
      if (l & 1) res += tree[l++]; // if l is a right child, its parent includes elements outside of our range [..l-1]
      if (!(r & 1)) res += tree[r--]; // if r is a left child, its parent includes elements outside our range [r+1..]
    }
    return res;
  }
  // query(1, 0, sz-1, l, r) --> note that lo and hi are all 0-based
  long long query(int node, int node_lo, int node_hi, int l, int r) {
    if (l <= node_lo && node_hi <= r) {
      return tree[node]; // current node's sum
    }
    if (node_lo > r || node_hi < l) {
      return 0; // identity value for disjoint node
    }
    // new range that the next nodes will encompass
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return query(2 * node, node_lo, end_low, l, r) +
           query(2 * node + 1, end_low + 1, node_hi, l, r);
  }
};
