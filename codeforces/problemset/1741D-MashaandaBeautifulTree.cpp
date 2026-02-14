#include <bits/stdc++.h>

#if 0
struct Node {
  int mn, mx;
  friend Node operator+(Node l, Node r) {
    return {std::min(l.mn,r.mn), std::max(l.mx,r.mx)};
  }
};

const int sz = (1 << 18);
Node tree[sz * 2];
void build(int n, std::vector<int>& a) {
  for (int i = 0; i < n; ++i) {
    tree[i+n] = {a[i], a[i]};
  }
  for (int i = n-1; i >= 1; --i) {
    tree[i] = tree[i*2] + tree[i*2+1];
  }
}
Node query(int node, int nlow, int nhigh, int qlow, int qhigh) {
  if (qlow <= nlow && nhigh <= qhigh) {
    return tree[node];
  }
  if (nlow > qhigh || nhigh < qlow) return {INT_MAX,INT_MIN};
  int m = nlow + (nhigh - nlow)/2;
  return query(node*2, nlow, m, qlow, qhigh) +
         query(node*2+1, m+1, nhigh, qlow, qhigh);
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  for (int i = 0; i+1 < n; i+=2) {
    if (std::abs(a[i+1]-a[i]) != 1 || std::min(a[i],a[i+1]) % 2 != 1) {
      std::cout << "-1\n";
      return;
    }
  }

  build(n, a);

  bool fail = 0;
  auto sol = [&](auto&& sol, int l, int r) -> int {
    if (fail || l == r) return 0;
    int m = l + (r-l)/2;
    Node left = query(1, 0, n-1, l, m), right = query(1, 0, n-1, m+1, r);
    // debug("Query[",l,r,"]:", "{", left.mx, left.mn, "vs" ,r-l, "}");
    if (left.mx - left.mn >  m-l || right.mx - right.mn > r-(m+1)) {
      fail = 1;
    }
    return sol(sol, l, m) + sol(sol, m+1, r) + (left.mn>right.mn ? 1: 0);
  };

  int res = sol(sol, 0, n-1);
  if (fail) res = -1;
  std::cout << res << "\n";
}
#endif

#define mp std::make_pair
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int res = 0;
  /* bool fail = 0; */
  auto sol = [&](auto&& sol, int l, int r) -> std::pair<int,int> {
    if (l == r) return mp(a[l], a[l]);
    int m = l + (r-l)/2;
    std::pair<int,int> left = sol(sol, l, m), right = sol(sol, m+1, r);
    if (left.first == -1) return mp(-1, -1);
    if (left.second+1 == right.first) return mp(left.first, right.second);
    if (right.second+1 == left.first) return ++res, mp(right.first, left.second);
    return mp(-1, -1);
  };
  std::pair<int,int> top = sol(sol, 0, n-1);
  if (top.first == -1) res = -1;
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
