// classic sieve up to max_n
vector<ll> sieve_up_to(ll max_n) {
  if (max_n < 2) return {};
  vector<bool> is_prime(max_n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i <= max_n; ++i) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= max_n; j += i) is_prime[j] = false;
    }
  }
  vector<ll> primes;
  primes.reserve(max_n / log(max_n)); // rough estimate
  for (ll i = 2; i <= max_n; ++i)
    if (is_prime[i]) primes.push_back(i);
  return primes;
}

// segmented sieve for [low, high]
vector<ll> sieve_range(ll low, ll high) {
  if (high < 2 || low > high) return {};
  if (low < 2) low = 2;

  ll limit = sqrt(high) + 1;
  auto base_primes = sieve_up_to(limit);
  vector<bool> is_prime(high - low + 1, true);
  for (ll p : base_primes) {
    ll start = max(p * p, ((low + p - 1) / p) * p);
    for (ll j = start; j <= high; j += p) is_prime[j - low] = false;
  }
  vector<ll> primes;
  for (ll i = 0; i <= high - low; ++i)
    if (is_prime[i]) primes.push_back(low + i);
  return primes;
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> ans;
  int n = nums.size();
  int len = (1 << n);             // powerset size: 2^n
  for (int i = 0; i < len; ++i) { // every set bits is the index to include
    vector<int> cur;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) cur.push_back(nums[j]);
    }
    ans.push_back(cur);
  }
  return ans;
}

// find the prime factors
vector<int> compute_prime_factors(int n) {
  vector<int> factors;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) factors.push_back(n); // n is prime
  return factors;
}

vector<int> divisors(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
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
const int MAX_N = 1e5 + 10;
vector<ll> fact(MAX_N), inv_fact(MAX_N);
void precompute_factorials(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = mod_mul(fact[i - 1], i);
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
