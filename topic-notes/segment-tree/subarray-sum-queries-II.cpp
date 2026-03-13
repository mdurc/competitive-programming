#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://cses.fi/problemset/task/3226
// SAME SOLUTION as subarray sum queries I, but just changing the query range

struct SGT {
  struct Node {
    // global max, max that starts at leftmost, max that ends at rightmost, sum
    ll g_max, l_max, r_max, sum;
    friend Node operator+(Node l, Node r) {
      return {max({l.g_max, r.g_max, l.r_max + r.l_max}),
              max(l.l_max, l.sum + r.l_max), max(r.r_max, l.r_max + r.sum),
              l.sum + r.sum};
    }
  };
  int n;
  vector<Node> tree;
  SGT(int sz) {
    n = 1;
    while (n < sz) n <<= 1;
    tree.assign(2 * n, {0,0,0,0});
  }
  void change(int idx, ll val) {
    if (val > 0) {
      tree[n + idx] = {val, val, val, val};
    } else {
      tree[n + idx] = {0,0,0,val};
    }
    for (int i = (n + idx) / 2; i >= 1; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  // query(1, 0, n-1, l, r) --> note that lo and hi are all 0-based
  Node query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
    if (query_lo <= node_lo && node_hi <= query_hi) {
      return tree[node];
    }
    if (node_lo > query_hi || node_hi < query_lo) {
      return {0,0,0,0};
    }
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return query(2 * node, node_lo, end_low, query_lo, query_hi) +
           query(2 * node + 1, end_low + 1, node_hi, query_lo, query_hi);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  SGT sg(n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sg.change(i, x);
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    cout << sg.query(1, 0, sg.n - 1, a-1, b-1).g_max << "\n";
  }

  return 0;
}
