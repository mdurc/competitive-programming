#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::map<int, std::vector<int>> m;
  std::vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
    m[b[i]].push_back(i);
  }
  int cur = 1;
  std::vector<int> res(n, 0);
  for (auto& [freq, idxs]: m) {
    int sz = (int)idxs.size();
    if (sz % freq != 0) {
      std::cout << "-1\n";
      return;
    }
    for (int i = 0; i < sz; ++i) {
      res[idxs[i]] = cur;
      if ((i+1)%freq == 0) ++cur;
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << res[i] << " ";
  }
  std::cout << "\n";
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

