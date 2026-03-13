#include <bits/stdc++.h>

bool cond(int mid, int m, int k, int n) {
  int other = mid-1;
  if (other == 0) return true;
  int lmax = k-1, rmax = n-k;
  // L <= lmax, (other-L) <= rmax
  int L_min = std::max(0, other-rmax);
  int L_max = std::min(other, lmax);
  if (L_min > L_max) return false;
  // min cost
  int target = other / 2;
  int bst_start;
  if (target < L_min) bst_start = L_min;
  else if (target > L_max) bst_start = L_max;
  else bst_start = target;
  return bst_start + (other-bst_start) + std::max(bst_start, (other-bst_start))-1 <= m;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int l = 1, r = n;
  while (l < r) {
    int mid = l + (r-l+1)/2;
    if (cond(mid, m, k, n)) {
      l = mid;
    } else {
      r = mid-1;
    }
  }
  std::cout << l << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
