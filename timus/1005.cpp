#include <bits/stdc++.h>

int solve(std::vector<int>& w, int idx = 0, int cura = 0, int curb = 0) {
  if (idx == (int)w.size()) return std::abs(cura-curb);
  return std::min(solve(w, idx+1, cura+w[idx], curb), solve(w, idx+1, cura, curb+w[idx]));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> w[i];
  }

  std::cout << solve(w) << "\n";

  return 0;
}
