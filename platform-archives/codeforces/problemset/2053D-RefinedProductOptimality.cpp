#include <bits/stdc++.h>

using ll = long long;
const int mod = 998244353;
int bpow(int a, int b=mod-2) {
  int res = 1;
  while (b) {
    if (b & 1) res = ((ll)res * a) % mod;
    a = ((ll)a * a) % mod;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  std::vector<int> ta = a, tb = b;
  std::sort(ta.begin(), ta.end());
  std::sort(tb.begin(), tb.end());

  int res = 1;
  for (int j = 0; j < n; ++j) {
    res = ((ll)res * std::min(ta[j], tb[j])) % mod;
  }

  std::cout << res << " ";

  for (int i = 0; i < q; ++i) {
    int o, x;
    std::cin >> o >> x, --x;
    if (o == 1) {
      int p = std::upper_bound(ta.begin(), ta.end(), a[x]) - ta.begin() - 1;
      if (ta[p] < tb[p]) res = (((ll)res * bpow(ta[p])) % mod) * (ta[p]+1) % mod;
      a[x]++, ta[p]++;
    } else {
      int p = std::upper_bound(tb.begin(), tb.end(), b[x]) - tb.begin() - 1;
      if (tb[p] < ta[p]) res = (((ll)res * bpow(tb[p])) % mod) * (tb[p]+1) % mod;
      b[x]++, tb[p]++;
    }
    std::cout << res << " ";
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
