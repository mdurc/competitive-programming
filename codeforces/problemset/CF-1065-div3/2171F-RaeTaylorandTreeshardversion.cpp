#include <bits/stdc++.h>

void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n), pos(n+1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }
  if (a[0] == 1) {
    std::cout << "YES\n";
    for (int i = 2; i <= n; ++i) {
      std::cout << 1 << " " << i << "\n";
    }
    return;
  }
  if (a[0] == n || a[n-1] == 1) {
    std::cout << "NO\n";
    return;
  }
  std::vector<int> suf(n);
  suf[n-1] = a[n-1];
  for (int i = n-2; i >= 0; --i) {
    suf[i] = std::max(a[i], suf[i+1]);
  }
  std::vector<std::pair<int,int>> res;
  for (int i = pos[1]+1; i < n; ++i) {
    res.push_back(std::make_pair(1, a[i]));
  }
  int last_val = 1, val = 2;
  while (1) {
    while (val <= n && pos[val] > pos[last_val]) ++val;
    if (val > n) break;
    for (int i = pos[val]+1; i < pos[last_val]; ++i) {
      res.push_back(std::make_pair(val, a[i]));
    }
    if (a[pos[val]] > suf[pos[last_val]]) {
      std::cout << "NO\n";
      return;
    }
    res.push_back(std::make_pair(val, suf[pos[last_val]]));
    last_val = val;
    ++val;
  }
  std::cout << "YES\n";
  for (std::pair<int,int>& p: res) {
    std::cout << p.first << " " << p.second << "\n";
  }
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
