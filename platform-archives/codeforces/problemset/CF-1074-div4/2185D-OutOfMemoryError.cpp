#include <bits/stdc++.h>

void solve() {
  int n, m, h;
  std::cin >> n >> m >> h;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)  {
    std::cin >> a[i];
    b[i] = a[i];
  }
  int last = 0;
  std::map<int,int> mp;
  for (int i = 1; i <= m; ++i) {
    int idx, c;
    std::cin >> idx >> c;
    --idx;
    if (mp[idx] != last) {
      b[idx] = a[idx];
      mp[idx] = last;
    }
    b[idx] += c;
    if (b[idx] > h) {
      b[idx] = a[idx];
      last = i;
      mp[idx] = last;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (mp[i] != last) b[i] = a[i];
    std::cout << b[i] << " ";
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
