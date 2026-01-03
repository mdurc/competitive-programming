#include <bits/stdc++.h>

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first >> a[i].second;
  }
  int res = 0, day = 1, needed = m;
  std::stack<std::pair<int, int>> s;
  auto process = [&](int target) -> void {
    while (!s.empty() && day < target) {
      auto [d, amt] = s.top();
      s.pop();
      if (day - d >= k) continue;
      if (d > day) {
        day = d;
        needed = m;
        if (day >= target) {
          s.push({d, amt});
          break;
        }
      }
      if (amt >= needed) {
        int end_day = std::min({day+(amt-needed)/m+1, d+k, target});
        int days_satisfied = end_day - day;
        if (days_satisfied > 0) {
          res += days_satisfied;
          int used = needed + (days_satisfied - 1) * m;
          int rem = amt - used;
          day = end_day;
          needed = m;
          if (rem > 0) s.push({d, rem});
        } else {
          s.push({d, amt});
          break;
        }
      } else {
        needed -= amt;
        // stay same day
      }
    }
    if (s.empty()) {
      day = target;
      needed = m;
    }
  };
  for (int i = 0; i < n; ++i) {
    process(a[i].first);
    s.push(a[i]);
  }
  process(1e9);
  std::cout << res << "\n";
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
