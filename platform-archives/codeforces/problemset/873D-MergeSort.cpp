#include <bits/stdc++.h>

int n, k, total = 1, a[100000];

void solve(int l, int r) {
  if (total >= k || r - l <= 1) return;
  total += 2;
  int mid = l + (r-l)/2;
  std::swap(a[mid - 1], a[mid]);
  solve(l, mid);
  solve(mid, r);
}

void solve() {
  std::cin >> n >> k;
  if (k % 2 == 0 || k > 2 * n - 1) {
    std::cout << "-1\n";
    return;
  }
  std::iota(a, a+n, 1);
  solve(0, n);
  for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
