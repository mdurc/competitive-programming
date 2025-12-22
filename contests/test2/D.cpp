#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  ll mxa, mxb;
  ll mna, mnb;
  friend Node operator+(Node l, Node r) {
    ll mxs[4] = {l.mxa, l.mxb, r.mxa, r.mxb};
    ll mns[4] = {l.mna, l.mnb, r.mna, r.mnb};
    sort(mxs, mxs + 4);
    sort(mns, mns + 4);
    return {mxs[3], mxs[2], mns[0], mns[1]};
  }
};

const ll INF = 1e18;
const ll NINF = -1e18;
const int mxn = 1e5 + 5;
Node tree[4 * mxn];
vector<ll> arr;

// change(1, 0, n-1, idx:0-based, value)
void change(int node, int node_lo, int node_hi, int idx, ll val) {
  if (node_lo == idx && node_hi == idx) {
    tree[node] = {val, NINF, val, INF};
    return;
  }
  if (node_lo > idx || node_hi < idx) return;
  int end_low = node_lo + (node_hi - node_lo) / 2;
  change(2 * node, node_lo, end_low, idx, val);
  change(2 * node + 1, end_low + 1, node_hi, idx, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// query(1, 0, n-1, l, r) --> note that lo and hi are all 0-based
Node query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
  if (query_lo <= node_lo && node_hi <= query_hi) {
    return tree[node];
  }
  if (node_lo > query_hi || node_hi < query_lo) {
    return {NINF, NINF, INF,INF};
  }
  int end_low = node_lo + (node_hi - node_lo) / 2;
  return query(2 * node, node_lo, end_low, query_lo, query_hi) +
         query(2 * node + 1, end_low + 1, node_hi, query_lo, query_hi);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    change(1, 0, n-1, i, a);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    Node p = query(1, 0, n - 1, l - 1, r - 1);
    ll res = max(p.mxa * p.mxb, p.mna * p.mnb);
    cout << res << "\n";
  }

  return 0;
}
