#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int islands = 0;
  int l = -1;
  bool has2 = 0;
  std::unordered_set<int> taken;
  for (int i = 0; i < n+1; ++i) {
    if (i < n) {
      if (a[i] == 2) has2 = 1;
      if (a[i] != 0 && l == -1) l = i;
    }
    if (i == n && l == -1) continue;
    if ((i == n && l != -1) || (a[i] == 0 && l != -1)) {
      ++islands;
      int r = i-1;
      bool x = l > 0 && a[l-1] == 0 && !taken.count(l-1);
      bool y = r+1 < n && a[r+1] == 0 && !taken.count(r+1);
      if (x) taken.insert(l-1);
      if ((!x && y) || (has2 && y)) taken.insert(r+1);
      l = -1;
      has2 = 0;
    }
  }

  int zeros = std::count(a.begin(), a.end(), 0);
  std::cout << islands+(zeros-taken.size()) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
