#include <bits/stdc++.h>

using ll = long long;

const int mod = 998244353;
const int mxn = 55;
ll fact[mxn], invf[mxn];

ll bpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b&1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
ll inv(ll a) { return bpow(a,mod-2); }

void precompute() {
  fact[0] = invf[0] = 1;
  for (int i = 1; i < mxn; ++i) {
    fact[i] = (fact[i-1]*i) % mod;
    invf[i] = inv(fact[i]);
  }
}
ll nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (fact[n]*((invf[r]*invf[n-r])%mod))%mod;
}

void solve() {
  int n;
  std::cin >> n;

  ll sum = 0;
  std::vector<ll> a(n+1);
  for (int i = 0; i <= n; ++i) {
    std::cin >> a[i];
    sum += a[i];
  }
  ll rounds = sum / n, extra = sum % n;

  int good = 0;
  ll need_for_zero = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > rounds) {
      good++;
    }
    if (a[i] < rounds) {
      need_for_zero += (rounds - a[i]);
    }
  }

  ll comb = 0;
  for (int i = 0; i <= (n-good); i++) {
    int cur = extra - i;
    if (cur < 0 || cur > good) continue;
    if (need_for_zero + i <= a[0]) {
      ll ways = nCr(n-good, i) * nCr(good, cur) % mod;
      comb = (comb + ways) % mod;
    }
  }
  std::cout << comb * fact[extra] % mod * fact[n - extra] % mod << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  precompute();
  while (t--) {
    solve();
  }

  return 0;
}
