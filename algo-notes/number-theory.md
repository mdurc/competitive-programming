## Number Theory

> **Primary topics:** primes, divisors, relationship between integers.

### Primes and Divisors
- **Terminology**:
    - A **factor/divsor** is a number that divides another number without any remainder.
    - A **prime number** is a whole number greater than 1 that has exactly two positive factors: 1 and itself.
    - A **composite number** is a whole number greater than 1 that is not prime.
        - 1 is neither prime or composite.

> **Fundamental Theorem of Arithmetic (Prime Factorization Theorem)**: Every number greater than 1 is either a prime number or can be **factorized** a product of primes (there is only one possible prime factorization).

- A naive check to see if $N$ is prime, or to find all its divisors, checks every number up to $N$.
- **Intuition:** Divisors always appear in pairs. If $d$ divides $N$, then $(N/d)$ also divides $N$. One of these divisors must be $\le \sqrt{N}$, and the other must be $\ge \sqrt{N}$. Therefore, we only ever need to iterate up to $\sqrt{N}$.

```cpp
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

bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
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
```

### Sieve of Eratosthenes
- For prime querying, $O(\sqrt{N})$ may be too slow, and precomputation of primes is more effective after the $O(N \log \log N)$ preprocessing.
- **Intuition:** Assume all numbers are prime. Start at 2. If it is marked prime, iterate through all of its multiples and mark them as composite. Move to the next number.

**Smallest Prime Factor (SPF) Optimization:** Instead of just marking numbers as boolean `true`/`false`, we can store the smallest prime factor for every number. This incredibly powerful optimization allows us to prime factorize *any* number up to $N$ in **$O(\log N)$ time**.

```cpp
const int mxn = 1e7 + 5;
int spf[mxn];
void sieve() {
  // when spf[i] = i, we know that i is prime (its own smallest prime factor)
  for (int i = 2; i < mxn; i++) spf[i] = i;
  for (int i = 2; i * i < mxn; i++) {
    if (spf[i] == i) { // i is prime
      for (int j = i * i; j < mxn; j += i) {
        // mark prime multiples as non-prime
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}

// fast prime factos O(log n)
std::vector<int> prime_factors(int n, bool unique = false) {
  std::vector<int> res;
  while (n > 1) {
    int p = spf[n];
    res.push_back(p);
    if (unique) while (n % p == 0) n /= p;
    else n /= p;
  }
  return res;
}
```

### GCD and LCM

- The **Greatest Common Divisor (GCD)** can be computed with `std::gcd(a, b)` in $O(\log(\min(a, b)))$ time.
- The **Least Common Multiple (LCM)** has a direct mathematical relationship with GCD: $\text{LCM}(a, b) = \frac{a \cdot b}{\gcd(a, b)}$

```cpp
// divide first to prevent intermediate overflow
long long lcm(long long a, long long b) { return (a / std::gcd(a, b)) * b; }
```

> **Extended Euclidean Algorithm** The standard Euclidean algorithm (GCD) can be *Extended* to find integer coefficients $x$ and $y$ that satisfy **Bézout's identity**: $ax + by = \gcd(a, b)$
- **Primary Application:** If we need the modular inverse of $a$ modulo $m$, but $m$ is **not prime** (meaning we cannot use [Fermat's Little Theorem](modular-arithmetic.md)), we can use the extended GCD.
    - Setting $b = m$, if $\gcd(a, m) = 1$, the equation becomes $ax + my = 1$. Taking this modulo $m$ leaves $ax \equiv 1 \pmod m$. Thus, $x$ is the modular inverse of $a$.

```cpp
// Returns gcd(a, b) and updates x and y to satisfy ax + by = gcd(a, b)
long long extGCD(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  long long x1, y1, d = extGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
```

### Euler's Totient Function ($\phi$)
- Euler's Totient function, $\phi(n)$, counts the number of integers between $1$ and $n$ that are coprime to $n$ ($\gcd(x, n) = 1$).
- If the prime factorization of $n$ is $p_1^{k_1} p_2^{k_2} \dots$, the formula is: $\phi(n) = n \cdot \left(1 - \frac{1}{p_1}\right) \cdot \left(1 - \frac{1}{p_2}\right) \dots$

> **Euler's Theorem:** generalization of Fermat's Little Theorem.
> For any coprime integers $a$ and $n$: $a^{\phi(n)} \equiv 1 \pmod n$

This allows us to reduce massive exponents when the modulo is not prime: $a^b \pmod n = a^{b \pmod{\phi(n)}} \pmod n$.

```cpp
long long phi(long long n) {
  long long res = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= res / i; // equivalent to res * (1 - 1/i)
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
```

### Resources
- https://en.wikipedia.org/wiki/Number_theory
