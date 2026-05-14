#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://cses.fi/problemset/task/1648

struct SGT {
  int n;
  vector<ll> tree;
  SGT(int sz) {
    n = 1;
    while (n < sz) n <<= 1; // next power of 2
    tree.assign(2 * n, 0LL);
  }
  void change(int idx, ll val) {
    tree[n+idx] = val;
    for (int i = (n+idx)/2; i >= 1; i/=2) {
      tree[i] = tree[2*i] + tree[2*i+1];
    }
  }
  // sum_query(1, 0, n-1, l, r) --> note that lo and hi are all 0-based
  ll sum_query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
    if (query_lo <= node_lo && node_hi <= query_hi) {
      return tree[node]; // current node's sum
    }
    if (node_lo > query_hi || node_hi < query_lo) {
      return 0; // current node is disjoint in query range
    }
    // new range that the next nodes will encompass
    int end_low = node_lo + (node_hi - node_lo) / 2;
    return sum_query(2 * node, node_lo, end_low, query_lo, query_hi) +
           sum_query(2 * node + 1, end_low + 1, node_hi, query_lo, query_hi);
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
      sg.change(a-1, b); // 1 based indexing
    } else {
      cout << sg.sum_query(1, 0, sg.n-1, a-1, b-1) << "\n";
    }
  }

  return 0;
}
