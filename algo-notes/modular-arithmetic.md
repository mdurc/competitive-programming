## Modular Arithmetic

- Since some problems have answers larger than the 64-bit maximum, many problems will ask for the answer modulo a large prime, typically $10^9 + 7$ or $998244353$.
- **Modular arithmetic** allows us to perform calculations as if we were working with standard integers, applying the modulo operation at *each step rather than just at the very end*.
    - This prevents overflowing during an intermediate computation in our program.

### Core Properties
When operating under a modulo $m$, the basic arithmetic operations (addition, subtraction, multiplication) distribute naturally.

* **Addition:** $(a + b) \pmod m = ((a \pmod m) + (b \pmod m)) \pmod m$
* **Multiplication:** $(a \cdot b) \pmod m = ((a \pmod m) \cdot (b \pmod m)) \pmod m$
* **Subtraction:** $(a - b) \pmod m = ((a \pmod m) - (b \pmod m) + m) \pmod m$
    * In C++, the `%` operator calculates the remainder, not the strict mathematical modulo. Thus if $a < b$, `(a - b) % m` will be negative. We must add $m$ before the final modulo to ensure the result wraps around into the positive range $[0, m-1]$.

> **Division** does not distribute naturally, we require more complex computation that is described later.

```cpp
const int MOD = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) { return ((a - b) % MOD + MOD) % MOD; }
long long mul(long long a, long long b) { return (a * b) % MOD; }
```

### Binary Exponentiation
- Calculating $a^b \pmod m$ iteratively by multiplying $a$ by itself $b$ times takes $O(b)$ time. If $b$ is $10^{18}$, this will cause a Time Limit Exceeded (TLE) verdict.
- **Intuition:** We can compute powers much faster by representing the exponent $b$ in binary (powers of 2). For example, $a^{13}$ can be written as $a^{8 + 4 + 1}$, which translates to $a^8 \cdot a^4 \cdot a^1$. By repeatedly squaring the base ($a \to a^2 \to a^4 \to a^8$), we only need to multiply the result by the current base when the corresponding bit in $b$ is $1$.
    - Reduces the time complexity from $O(b)$ to $O(\log b)$.
```cpp
long long binpow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;  // If the lowest bit is 1, multiply into result
        base = (base * base) % MOD;             // Square the base
        exp >>= 1;                              // Shift exponent right
    }
    return res;
}
```

*(Note: same logic is used to achieve $O(\log n)$ matrix transitions for [Matrix Exponentiation](matrices.md))*

### Modular Inverse
- Division is the only basic operation that **does not** distribute over modulo.
    - $(a / b) \pmod m \neq ((a \pmod m) / (b \pmod m)) \pmod m$.

- Instead of dividing by $b$, we must multiply by the **modular multiplicative inverse** of $b$.
    - The inverse of $b$, denoted as $b^{-1}$, is a number such that: $(b \cdot b^{-1}) \equiv 1 \pmod m$

> **Fermat's Little Theorem**
> If $m$ is a prime number and $b$ is not divisible by $m$: $b^{m-1} \equiv 1 \pmod m$

- If we divide both sides by $b$, we get: $b^{m-2} \equiv b^{-1} \pmod m$
- This means **the modular inverse of $b$ is simply $b^{m-2} \pmod m$**.
    - This can be computed with the binary exponentiation function!

*(Note: If the modulo $m$ is ever not prime, Fermat's Little Theorem cannot be used. You must use the [Extended Euclidean Algorithm](number-theory.md) instead).*

```cpp
long long mod_inv(long long n) { return binpow(n, MOD - 2); }
long long mod_div(long long a, long long b) { return (a * mod_inv(b)) % MOD; }
```

**Common Application:** The primary reason we need modular division is to compute `nCr` (combinations) for [combinatorics](combinatorics.md) and DP. The formula $\frac{n!}{k!(n-k)!}$ requires us to divide by factorials, meaning we must multiply by the modular inverse of those factorials.
