#include <bits/stdc++.h>

using ll = long long;

struct person {
  int id, a;
  std::vector<int> s;
};
void solve() {
  int n, p, k;
  std::cin >> n >> p >> k;
  std::vector<person> people(n);
  for (int i = 0; i < n; ++i) {
    people[i].id = i;
    std::cin >> people[i].a;
  }
  for (int i = 0; i < n; ++i) {
    people[i].s.resize(p);
    for (int j = 0; j < p; ++j) {
      std::cin >> people[i].s[j];
    }
  }
  sort(people.begin(), people.end(), [](const person& a, const person& b) {
      return a.a > b.a;
      });
  // dp[i][mask] max strength of items 1..i, of mask positions
  std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(1 << p, -1));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int mask = 0; mask < (1 << p); ++mask) {
      if (dp[i-1][mask] == -1) continue;
      for (int j = 0; j < p; ++j) {
        if (!((mask >> j) & 1)) {
          int nmask = mask | (1 << j);
          dp[i][nmask] = std::max(dp[i][nmask], dp[i-1][mask] + people[i-1].s[j]);
        }
      }
      int audience_selected = i-1 - __builtin_popcount(mask);
      dp[i][mask] = std::max(dp[i][mask], dp[i-1][mask]+(audience_selected < k ? people[i-1].a: 0));
    }
  }
  std::cout << dp[n][(1 << p) - 1] << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
