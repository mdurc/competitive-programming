#include <bits/stdc++.h>

std::vector<int> get(int x){
  std::vector<int> res = {x};
  while (__builtin_popcount(x) > 1) {
    x -= (x & -x); // clear lowest bit
    res.push_back(x);
  }
  while (x > 1) {
    x /= 2;
    res.push_back(x);
  }
  return res;
}

void solve() {
  int x;
  std::cin >> x;

  std::vector<int> res = get(x);
  std::cout << res.size() << "\n";
  for (int i: res) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
