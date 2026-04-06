#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    auto it = std::lower_bound(a.begin(), a.end(), x);
    if (it == a.end()) {
      a.push_back(x);
      continue;
    }
    *it = x;
  }

  int res = (int)a.size();
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
