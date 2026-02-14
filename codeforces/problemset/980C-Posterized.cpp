#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::map<int, int> m;
  for (int i = 0; i < n; ++i) {
    int a, cur;
    std::cin >> a, cur = a;
    if (m.find(a) != m.end()) {
      std::cout << m[a] << " ";
      continue;
    }
    for (int j = 0; j < k; ++j) {
      cur--;
      if (cur < 0 || m.find(cur) != m.end()) break;
    }
    int start_node;
    if (cur >= 0 && m.find(cur) != m.end() && a-m[cur] <= k-1) {
      start_node = m[cur];
    } else {
      start_node = cur+1;
    }
    for (int j = start_node; j <= a; ++j) {
      m[j] = start_node;
    }
    std::cout << m[a] << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
