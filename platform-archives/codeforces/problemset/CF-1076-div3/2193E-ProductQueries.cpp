#include <bits/stdc++.h>

const int mxn = 3e5+1;
std::vector<int> factors[mxn];
int cnt[mxn];

void precompute() {
  for (int i = 1; i < mxn; ++i) {
    for (int j = i; j < mxn; j += i) {
      factors[j].push_back(i);
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::fill(cnt, cnt+n+1, 1e9);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    cnt[a[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] == 1) {
      std::cout << 1 << " ";
      continue;
    }
    for (int f: factors[i]) {
      if (cnt[f] != -1 && cnt[i/f] != -1) {
        cnt[i] = std::min(cnt[i], cnt[f] + cnt[i/f]);
      }
    }
    std::cout << (cnt[i] == 1e9 ? -1: cnt[i]) << " ";
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  precompute();

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
