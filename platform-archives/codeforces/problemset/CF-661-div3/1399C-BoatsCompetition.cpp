#include <bits/stdc++.h>

void solve1() {
  int n;
  std::cin >> n;
  std::vector<int> w(n);
  std::map<int,int> freq;
  for (int i = 0; i < n; ++i) {
    std::cin >> w[i];
    freq[w[i]]++;
  }
  std::sort(w.begin(), w.end());
  auto get = [&](int target) -> int {
    std::map<int,int> tmp = freq;
    int amt = 0;
    for (int i = 0; i < n; ++i) {
      if ((w[i] == target-w[i] && tmp[w[i]] > 1) ||
          (w[i] != target-w[i] && tmp[w[i]] > 0 && tmp[target-w[i]] > 0)) {
        tmp[w[i]]--, tmp[target-w[i]]--;
        ++amt;
      }
    }
    return amt;
  };
  int res = 0;
  for (int i = 2; i <= 100; ++i) {
    res = std::max(res, get(i));
  }
  std::cout << res << "\n";
}

void solve() {
  int n;
  std::cin >> n;
  int cnt[105] = {0};
  for (int i = 0; i < n; ++i) {
    int w;
    std::cin >> w;
    cnt[w]++;
  }
  int res = 0;
  for (int s = 2; s <= 2*n; ++s) {
    int cur = 0;
    for (int i = 1; i*2 <= s; ++i) {
      int j = s - i;
      if (j > n) continue;
      if (i == j) {
        cur += cnt[i]/2;
      } else {
        cur += std::min(cnt[i], cnt[j]);
      }
    }
    res = std::max(res, cur);
  }
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
