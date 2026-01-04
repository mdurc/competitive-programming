#include <bits/stdc++.h>
using ll = long long;
const int mxn = 2e5 + 5;
bool is_prime[mxn];
int min_prime_factor[mxn];

// computes primes and min_prime_factor up to n in O(n log n)
std::vector<int> sieve(int n = mxn) {
  std::fill(is_prime, is_prime + n, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i*i < n; ++i) {
    if (is_prime[i]) {
      for (int j = i*i; j < n; j += i) {
        is_prime[j] = false;
        if (min_prime_factor[j] == 0) {
          min_prime_factor[j] = i;
        }
      }
    }
  }
  std::vector<int> res;
  for (int i = 2; i < n; ++i) {
    if (is_prime[i]) {
      res.push_back(i);
      min_prime_factor[i] = i;
    }
  }
  return res;
}

// all/unique prime factors of n, using min_prime_factor from sieve. O(log n)
std::vector<int> prime_factors(int n, bool unique = false) {
  std::vector<int> res;
  while (n > 1) {
    int p = min_prime_factor[n];
    res.push_back(p);
    if (unique) while (n % p == 0) n /= p;
    else n /= p;
  }
  return res;
}

// all prime factors of n, no precomputation. O(sqrt(n))
std::vector<int> prime_factors(int n) {
  std::vector<int> res;
  for (int i = 2; i*i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}

// all divisors of n. O(sqrt(n))
std::vector<int> factors(int n) {
  std::vector<int> res;
  for (int i = 1; i*i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

// all 2^n subsets. O(n * 2^n), thus n <= 20
std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> res;
  int n = (int)nums.size();
  int len = (1 << n);             // powerset size: 2^n
  for (int i = 0; i < len; ++i) { // every set bits is the index to include
    std::vector<int> cur;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) cur.push_back(nums[j]);
    }
    res.push_back(cur);
  }
  return res;
}

// O(log(min(a, b))), just use std::gcd and std::lcm
ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Modular Arithmetic
const int MOD = 1e9 + 7;
ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a * b) % MOD; }
ll mod_pow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = mod_mul(res, a);
    a = mod_mul(a, a);
    b >>= 1;
  }
  return res;
}
// fermats: If p is prime and the gcd(a,p) = 1 then a^p = a mod p
// mod must be prime for fermat's little theorem
ll mod_inv(ll a) { return mod_pow(a, MOD - 2); }
ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)); }

// Combinatorics
ll fact[mxn], inv_fact[mxn];
void precompute_factorials(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = mod_mul(fact[i - 1], i);
  inv_fact[n] = mod_inv(fact[n]);
  for (int i = n - 1; i >= 0; i--) {
    inv_fact[i] = mod_mul(inv_fact[i + 1], i + 1);
  }
}
ll nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return mod_mul(fact[n], mod_mul(inv_fact[r], inv_fact[n - r]));
}
ll nPr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return mod_mul(fact[n], inv_fact[n - r]);
}
