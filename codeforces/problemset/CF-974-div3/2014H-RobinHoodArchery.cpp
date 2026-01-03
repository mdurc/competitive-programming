#include <bits/stdc++.h>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

using ull = unsigned long long;

const int mxa = 1e6 + 5;
ull hash[mxa];

void precompute() {
  for (int i = 1; i < mxa; ++i) {
    hash[i] = rng();
  }
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<ull> pref(n+1);
  for (int i = 1; i <= n; ++i) {
    int a;
    std::cin >> a;
    pref[i] = pref[i-1] ^ hash[a];
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    if ((pref[r]^pref[l-1]) == 0) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
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
