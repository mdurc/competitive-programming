#include <bits/stdc++.h>

const int mxn = 2e5+5;
int min_prime_factor[mxn];
bool seen_primes[mxn];
std::vector<int> used;

void sieve() {
  for (int i = 2; i*i < mxn; ++i) {
    if (min_prime_factor[i] == 0) {
      for (int j = i*i; j < mxn; j += i) {
        if (min_prime_factor[j] == 0) min_prime_factor[j] = i;
      }
    }
  }
  for (int i = 2; i < mxn; ++i) {
    if (min_prime_factor[i] == 0) min_prime_factor[i] = i;
  }
}
std::vector<int> prime_factors(int n) {
  std::vector<int> res;
  while (n > 1) {
    int p = min_prime_factor[n];
    res.push_back(p);
    while (n % p == 0) n /= p;
  }
  return res;
}
void solve() {
  for (int i: used) seen_primes[i] = 0;
  used.clear();

  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  int evens = 0;
  bool done = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] % 2 == 0) ++evens;
    if (!done) {
      std::vector<int> f = prime_factors(a[i]);
      for (int p: f) {
        if (seen_primes[p]) done = 1;
        seen_primes[p] = 1;
        used.push_back(p);
      }
    }
  }
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  if (done) {
    std::cout << "0\n";
  } else if (evens > 0) {
    std::cout << "1\n";
  } else {
    for (int i = 0; i < n; ++i) {
      std::vector<int> f = prime_factors(a[i]+1);
      for (int p : f) {
        if (seen_primes[p]) {
          std::cout << "1\n";
          return;
        }
      }
    }
    std::cout << "2\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sieve();

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
