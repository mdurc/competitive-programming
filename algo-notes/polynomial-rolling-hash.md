## Polynomial Rolling Hash

> **TL;DR:** This is a versitile technique that can handle the majority of string problems. It converts substrings into integers, allowing you to perform $O(1)$ string comparisons after $O(N)$ preprocessing.

**Handles:** Pattern matching, longest common prefix of two suffixes, longest palindromes, lexicographic string comparisons, and more.

### 1. Hashing

- A string can be represented as a sequence of numbers: `'a' = 1, 'b' = 2, 'c' = 3, ...`.
    - During the implementation we can treat each character $c$ as either its ASCII value, or alphabetic-index (1-based).
    - Note that if we hash characters as their alphabetic-index, we cannot use `0` because it will contribute nothing to the hash, thus `"aaa"` would be equivalent to `"aa"`.

- Polynomial hashing treats this sequence of $n$ characters as the coefficients of a polynomial of base $P$.
    - $H(S) = S[0] \cdot P^{n-1} + S[1] \cdot P^{n-2} + \dots + S[n-1] \cdot P^0$
- **Why a polynomial:** This representation particularly useful because it allows us to "shift" values easily. If we have the hash of "abc", and we want to determine the hash of "bcd", we can subtract the contribution of 'a', then multiply the rest of $P$ to shift everything up by one power, and add 'd'.
    - With $P = 5$:
        - $H(\text{'abc'}) = 1 \cdot 5^2 + 2 \cdot 5^1 + 3 \cdot 5^0 = 38$
        - $H(\text{'bcd'}) = (H(\text{'abc'}) - (1 \cdot 5^2)) \cdot 5 + 4 \cdot 5^0 = 69$
    - It is also possible to easily modify a character and provide the new hash value:
        - Since each character contributes $[\text{char} \cdot P^{(n - \text{pos} - 1)}]$ to the hash-sum, we can simply remove that contribution from the hash, and add the new contribution from the new character.

- During implementation we also have to guard against overflow, so we perform modulo $M$ on each hash value:
    - $H(S) = (S[0] \cdot P^{n-1} + S[1] \cdot P^{n-2} + \dots + S[n-1] \cdot P^0) \pmod M$

### 2. Substring Queries (Prefix Sums for Strings)

- To get the hash of any substring $S[l \dots r]$ in $O(1)$ time, we use a concept identical to [prefix sums](prefix-sum.md).
    - If we precompute the hash of every prefix of the string, we can isolate a substring by taking the hash of the prefix ending at $r$, and subtracting the prefix ending at $l-1$.
    - However, because the prefix at $l-1$ is evaluated at higher powers of $P$, we must align them by multiplying it by $P^{r-l+1}$ before subtracting.

$$H(l, r) = \left(H[r] - H[l-1] \cdot P^{r-l+1} \right) \pmod M$$

- **To compute the hash-prefix-sum:**
    - $H[0] = S[0]$
    - $H[i] = H[i-1] \cdot P + S[i]$

- For $S =\text{abcdef}$, $P = 5$:
    - $H[0] = 1 \cdot 5^0 = 1$
    - $H[1] = 1 \cdot 5 + 2 \cdot 5^0 = 7$
    - $H[2] = 7 \cdot 5 + 3 \cdot 5^0 = 38$
    - $H[3] = 38 \cdot 5 + 4 \cdot 5^0 = 194$
    - $H[4] = 194 \cdot 5 + 5 \cdot 5^0 = 975$
    - $H(\text{'abcdef'}) = H[5] = 975 \cdot 5 + 6 \cdot 5^0 = 4881$
- If we want $H(\text{'cde'})$, we are querying (0-based) $[2, 4]$:
    - We want to remove the `"ab"` prefix from the `"abcde"` hash.
        - `"abcde"`: $H[4] = 1 \cdot 5^4 + 2 \cdot 5^3 + \mathbf{3 \cdot 5^2 + 4 \cdot 5^1 + 5 \cdot 5^0}$
        - `"ab"`: $H[1] = 1 \cdot 5^1 + 2 \cdot 5^0$
    - We cannot simply perform $H[4] - H[1]$ because the powers $5^n$ are not aligned properly.
    - Shifting $H[1]$'s powers by $r-l+1 = 3$ will yield: $(1 \cdot 5^1 + 2 \cdot 5^0) \cdot \mathbf{5^3} = 1 \cdot 5^4 + 2 \cdot 5^3$
    - Now we have the correct prefix of `"ab"` that exists in the hash-prefix for `"abcde"`.
    - $H(2, 4) = H[4] - (1 \cdot 5^4 + 2 \cdot 5^3) = 3 \cdot 5^2 + 4 \cdot 5^1 + 5 \cdot 5^0$
    - $H(2, 4) = 3(25) + 4(5) + 5(1) = 100$

- **To precompute the powers of $P$:**:
  - $p[0] = 1$
  - $p[i] = p[i-1] \cdot P$

### Implementation 1: Educational Approach

This approach is more readable and more intuitive based on the logic we have discussed. See [modular arithmetic notes](modular-arithmetic.md) to understand how we safely perform modulo operations on addition and subtraction.

```cpp
int P1 = 31; // some prime, sometimes 37
int M1 = 1e9 + 7; 
const int mxn = 1e6 + 5;
string s; int n;
long long hash_f[mxn]; // forward hashes: hash of substring of length i
long long hash_r[mxn]; // reverse hashes
long long pow_p1[mxn]; // precomuted powers for substring hashes

void precompute() {
  pow_p1[0] = 1;
  for (int i = 1; i < mxn; ++i) {
    pow_p1[i] = (pow_p1[i-1] * P1) % M1;
  }
}

long long compute_hash() {
  // forward hashes: s[0]*p^n + s[1]*p^(n-1) + s[2]*p^(n-2) .. mod m
  hash_f[0] = hash_r[n] = 0;
  for (int i = 0; i < n; ++i) {
    hash_f[i + 1] = ((hash_f[i] * P1)%M1 + s[i]) % M1;
  }
  for (int i = n - 1; i >= 0; --i) {
    hash_r[i] = ((hash_r[i + 1] * P1)%M1 + s[i]) % M1;
  }
  return hash_f[n]; // full string hash
}
long long change_char(long long h1, int pos, char newc, char oldc) {
  // Each character contributes [char_value * P^(n-pos-1)]
  long long exp = pow_p1[n-pos-1];
  return ((h1 - (oldc * exp)%M1 + (newc * exp)%M1) + M1) % M1;
}
long long get(int l, int r, bool get_fwd = true) { // 0-based indexing
  long long fwd = ((hash_f[r+1] - (hash_f[l] * pow_p1[r-l+1])%M1) + M1) % M1;
  long long rev = ((hash_r[l] - (hash_r[r+1] * pow_p1[r-l+1])%M1) + M1) % M1;
  return get_fwd ? fwd : rev;
}
```

**As described in more detail below, a single-hash approach is often not sufficient due to the number of collisions that can occur. String hashing is often implemented as double-polynomial hash instead**
The implementation is largely the same, but simply tracking another hash-prefix-sum for each computation. Then, instead of returning a single hash-value, we return a pair of hash-values. Two strings will have the same hash if both hash-values are identical.
```cpp
const int P1 = 31, P2 = 37; // 131
const int M1 = 1e9 + 7, M2 = 1e9 + 9;
const int mxn = 1e6 + 5;
string s; int n;
long long h_f1[mxn], h_f2[mxn]; // forward hashes
long long h_r1[mxn], h_r2[mxn]; // reverse hashes
long long p1[mxn], p2[mxn];     // precomputed powers
void precompute() {
  p1[0] = p2[0] = 1;
  for (int i = 1; i < mxn; ++i) {
    p1[i] = (p1[i-1] * P1) % M1;
    p2[i] = (p2[i-1] * P2) % M2;
  }
}
std::pair<long long, long long> compute_hash() {
  h_f1[0] = h_f2[0] = h_r1[n] = h_r2[n] = 0;
  for (int i = 0; i < n; ++i) {
    h_f1[i + 1] = ((h_f1[i] * P1)%M1 + s[i]) % M1;
    h_f2[i + 1] = ((h_f2[i] * P2)%M2 + s[i]) % M2;
  }
  for (int i = n - 1; i >= 0; --i) {
    h_r1[i] = ((h_r1[i + 1] * P1)%M1 + s[i]) % M1;
    h_r2[i] = ((h_r2[i + 1] * P2)%M2 + s[i]) % M2;
  }
  return std::make_pair(h_f1[n], h_f2[n]);
}
std::pair<long long, long long> change_char(std::pair<long long, long long> h, int pos, char newc, char oldc) {
  long long e1 = p1[n-pos-1];
  long long e2 = p2[n-pos-1];
  long long hash1 = ((h.first - (oldc * e1)%M1 + (newc * e1)%M1) + M1) % M1;
  long long hash2 = ((h.second - (oldc * e2)%M2 + (newc * e2)%M2) + M2) % M2;
  return std::make_pair(hash1, hash2);
}
std::pair<long long, long long> get(int l, int r, bool get_fwd = true) { // 0-based indexing
  long long hash1, hash2;
  if (get_fwd) {
    hash1 = ((h_f1[r+1] - (h_f1[l] * p1[r-l+1])%M1) + M1) % M1;
    hash2 = ((h_f2[r+1] - (h_f2[l] * p2[r-l+1])%M2) + M2) % M2;
  } else {
    hash1 = ((h_r1[l] - (h_r1[r+1] * p1[r-l+1])%M1) + M1) % M1;
    hash2 = ((h_r2[l] - (h_r2[r+1] * p2[r-l+1])%M2) + M2) % M2;
  }
  return std::make_pair(hash1, hash2);
}
```

### Implementation 2: Template

This version is a more optimized, and safer, template that can be used when the test cases are *anti-hash*. Because hashes are not perfect, and collisions exist, it is possible for a test-case to be written such that a particular collision occurs and thus our algorithm fails.

* **Implicit Modulo:** Instead of using the slow `%` operator, this utilizes integer overflow mechanics to compute the hash mathematically. The custom struct overloads operators to emulate arithmetic over the field $2^{64}-1$. In most cases we could also simply replace `H` with the `unsigned long long` type and rely on standard overflow/underflow.
* **Anti-Hash Collisions:** $2^{64}-1$ is not a prime number, meaning specific test cases can be crafted to force hash collisions. This template defends against that by choosing a **randomized base $C$** at runtime (`rng()`), ensuring that the base is co-prime to the modulo (`std::gcd(C.x, -1ULL) != 1`). This makes it impossible setters to pre-calculate collisions.

```cpp
// using H = unsigned long long; // for no anti-hash test cases (2x faster)
struct H {
  unsigned long long x; H(unsigned long long x=0) : x(x) {}
  H operator+(H o) { return x + o.x + (x + o.x < x); }
  H operator-(H o) { return *this + ~o.x; }
  H operator*(H o) { auto m = (unsigned __int128)x * o.x; return H((unsigned long long)m) + (unsigned long long)(m >> 64); }
  unsigned long long get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};

// static const H C = (long long)1e11+3;
static H C; // randomized base
struct HashInterval {
  int n;
  std::vector<H> hash_f, hash_r; // hash of substring of length i
  std::vector<H> pow;
  HashInterval(std::string& s): n((int)s.size()), hash_f(n+1), hash_r(n+1), pow(hash_f) {
    pow[0] = 1;
    for (int i = 0; i < n; ++i) {
      // forward hashes: s[0]*p^n + s[1]*p^(n-1) + s[2]*p^(n-2) .. mod m
      hash_f[i+1] = hash_f[i] * C + s[i];
      hash_r[n-i-1] = hash_r[n-i] * C + s[n-i-1];
      pow[i+1] = pow[i] * C;
    }
  }
  H get(int l, int r, bool get_fwd = true) { // hash [a, b] -- 0 based
    H fwd = hash_f[r+1] - hash_f[l] * pow[r-l+1];
    H rev = hash_r[l] - hash_r[r+1] * pow[r-l+1];
    return get_fwd ? fwd : rev;
  }
  H change_char(H h1, int pos, char newc, char oldc) {
    // each character contributes [char_value * P^(n-pos-1)]
    return h1 - pow[n-pos-1] * oldc + pow[n-pos-1] * newc;
  }
};

// often times we don't need to do a full forward/backward prefix hash
// on a string, and we simply want the full hash-sum.
H hashString(std::string& s) { H h; for(char c: s) h=h*C+c; return h; }

int main() {
  std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  C = H(rng());
  while (std::gcd(C.x, -1ULL) != 1) {
    C = H(rng());
  }
}
```

### Resources
* https://codeforces.com/blog/entry/60445
