#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n, ax, ay, bx, by;
  std::cin >> n >> ax >> ay >> bx >> by;
  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  std::map<int, std::pair<int, int>> ys;
  for (int i = 0; i < n; ++i) {
    int y;
    std::cin >> y;
    if (ys.find(x[i]) == ys.end()) {
      ys[x[i]] = std::make_pair(y,y);
    } else {
      ys[x[i]].first = std::min(ys[x[i]].first, y);
      ys[x[i]].second = std::max(ys[x[i]].second, y);
    }
  }
  ll px = ax, prev_mny = ay, prev_mxy = ay, costmin = 0, costmax = 0;
  for (auto& [curx, range]: ys) {
    auto [curmin, curmax] = range;
    ll dx = curx - px;
    ll dy = curmax - curmin;
    ll low_to_low = costmin + abs(curmax - prev_mny) + dy + dx;
    ll high_to_low = costmax + abs(curmax - prev_mxy) + dy + dx;
    ll low_to_high = costmin + abs(curmin - prev_mny) + dy + dx;
    ll high_to_high = costmax + abs(curmin - prev_mxy) + dy + dx;
    px = curx;
    prev_mny = curmin, prev_mxy = curmax;
    costmin = std::min(low_to_low, high_to_low);;
    costmax = std::min(low_to_high, high_to_high);
  }
  ll dx = bx - px;
  std::cout << std::min(costmin + abs(by - prev_mny) + dx, costmax + abs(by - prev_mxy) + dx) << "\n";
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
