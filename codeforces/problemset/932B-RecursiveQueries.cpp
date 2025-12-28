#include <bits/stdc++.h>

using ll = long long;

const int mxn = 1e6 + 1;
bool seen[mxn];
int memo[mxn];
int f(int x) {
  int res = 1;
  while (x > 0) {
    if (x % 10 != 0) res *= x % 10;
    x /= 10;
  }
  return res;
}
int g(int x) {
  if (x < 10) return x;
  if (seen[x]) return memo[x];
  return memo[x] = g(f(x));
}

// --- segment tree solution
const int n = 1 << 20;
int tree[n * 2][9]; // next pwr of 2, * 2
void build() {
  for (int i = 0; i < mxn - 1; ++i) {
    int res = g(i+1)-1;
    tree[n+i][res] = 1;
  }
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 0; j < 9; ++j) {
      tree[i][j] = tree[2 * i][j] + tree[2 * i + 1][j];
    }
  }
}
int query(int k, int node, int node_lo, int node_hi, int query_lo, int query_hi) {
  if (query_lo <= node_lo && node_hi <= query_hi) {
    return tree[node][k];
  }
  if (node_lo > query_hi || node_hi < query_lo) {
    return 0;
  }
  int end_low = node_lo + (node_hi - node_lo) / 2;
  return query(k, 2 * node, node_lo, end_low, query_lo, query_hi) +
         query(k, 2 * node + 1, end_low + 1, node_hi, query_lo, query_hi);
}

void solve1() {
  int l, r, k;
  std::cin >> l >> r >> k;
  std::cout << query(k-1,1,0,n-1,l-1,r-1) << "\n";
}
// ---

// --- prefix sums solution, no need for segment tree due to no updates
int p[mxn][9];
void precompute() {
  for (int i = 1; i < mxn; ++i) {
    for (int j = 0; j < 9; ++j) {
      p[i][j] = p[i-1][j];
    }
    p[i][g(i)-1]++;
  }
}
void solve() {
  int l, r, k;
  std::cin >> l >> r >> k;
  std::cout << p[r][k-1] - p[l-1][k-1] << "\n";
}
// ---

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  // build();
  precompute();
  while (t--) {
    solve();
  }

  return 0;
}
