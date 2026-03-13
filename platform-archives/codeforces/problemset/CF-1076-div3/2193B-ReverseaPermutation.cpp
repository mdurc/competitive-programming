#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (a[i] != n-i) {
      std::reverse(a.begin()+i, std::find(a.begin()+i, a.end(), n-i)+1);
      break;
    }
  }
  for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
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
