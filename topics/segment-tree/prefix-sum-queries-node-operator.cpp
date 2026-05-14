#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://cses.fi/problemset/task/2166

struct SGT {
  struct Node {
    ll sum, pref;
    friend Node operator+(Node l, Node r) {
      return {l.sum + r.sum, max(l.pref, l.sum + r.pref)};
    }
  };
  int n;
  vector<Node> tree;
  SGT(int sz) {
    n = 1;
    while (n < sz) n <<= 1; // next power of 2
    tree.assign(2 * n, {0, 0});
  }
  void change(int idx, ll val) {
    tree[n+idx] = {val, max(val, 0LL)};
    for (int i = (n+idx)/2; i >= 1; i/=2) {
      tree[i] = tree[2*i] + tree[2*i+1];
    }
  }
  // query(1, 0, n-1, l, r) --> note that lo and hi are all 0-based
  Node query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
    if (query_lo <= node_lo && node_hi <= query_hi) {
      return tree[node];
    }
    if (node_lo > query_hi || node_hi < query_lo) {
      return {0, 0};
    }
    // new range that the next nodes will encompass
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return query(2 * node, node_lo, end_low, query_lo, query_hi) +
           query(2 * node + 1, end_low + 1, node_hi, query_lo, query_hi);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  SGT sg(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sg.change(i, x);
  }

  for (int i = 0; i < q; ++i) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      sg.change(a-1, b);
    } else {
      cout << sg.query(1, 0, sg.n-1, a-1, b-1).pref << "\n";
    }
  }

  return 0;
}
