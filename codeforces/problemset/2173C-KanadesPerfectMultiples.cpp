#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  n = a.size();

  // B must include a divisor of the smallest value
  // we want it to be maximized so that we don't require all of the multiples,
  // thus we include the number itself, as its own divisor
  // if it takes all of multiples of a, then B is finished,
  //   otherwise we do the same thing with the next lowest value in a

  std::vector<bool> vis(n, false);
  std::vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    if (k/a[i] > n) {
      std::cout << "-1\n";
      return;
    }
    bool ok = 1;
    std::vector<int> multiples;
    for (int m = 1; m <= k/a[i]; ++m) {
      int target = a[i] * m;
      auto it = std::lower_bound(a.begin(), a.end(), target);
      if (it == a.end() || *it != target) {
        ok = 0;
        break;
      }
      multiples.push_back(it-a.begin());
    }
    if (!ok) {
      std::cout << "-1\n";
      return;
    }
    res.push_back(a[i]);
    for (int idx : multiples) {
      vis[idx] = 1;
    }
  }

  std::cout << res.size() << "\n";
  for (int i: res) {
    std::cout << i << " ";
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
