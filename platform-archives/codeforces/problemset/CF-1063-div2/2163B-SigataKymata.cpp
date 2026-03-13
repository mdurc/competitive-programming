#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  std::string s;
  std::cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1' && (i == 0 || i == n-1 || p[i] == 1 || p[i] == n)) {
      std::cout << "-1\n";
      return;
    }
  }
  int a = std::find(p.begin(),p.end(),1)-p.begin()+1;
  int b = std::find(p.begin(),p.end(),n)-p.begin()+1;
  if (a > b) std::swap(a, b);
  std::cout << "5\n";
  std::cout << 1 << " " << a << "\n";
  std::cout << 1 << " " << b << "\n";
  std::cout << a << " " << b << "\n";
  std::cout << a << " " << n << "\n";
  std::cout << b << " " << n << "\n";
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
