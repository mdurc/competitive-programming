#include <bits/stdc++.h>

void solve() {
  int n, d, k;
  std::cin >> n >> d >> k;
  std::vector<int> l_suf(n+1), r_pref(n+1);
  for (int i = 0; i < k; ++i) {
    int l, r;
    std::cin >> l >> r;
    l_suf[l-1]++;
    r_pref[r]++;
  }
  for (int i = 1; i <= n; ++i) r_pref[i] += r_pref[i-1];
  for (int i = n-1; i >= 0; --i) l_suf[i] += l_suf[i+1];
  int mx = INT_MIN, mn = INT_MAX;
  int a = -1, b = -1;
  for (int i = 0; i+d-1 < n; ++i) {
    int outside = r_pref[i] + l_suf[i+d];
    if ((k-outside) > mx) {
      mx = (k-outside);
      a = i+1;
    }
    if ((k-outside) < mn) {
      mn = (k-outside);
      b = i + 1;
    }
  }
  std::cout << a << " " << b << "\n";
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
