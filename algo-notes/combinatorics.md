## Combinatorics

Because the results from combinatorial calculations grow factorially, standard integer types will overflow, making combinatorics deeply intertwined with [Modular Arithmetic](modular-arithmetic.md).

### Combinations vs. Permutations
* **Permutations (Order Matters):** Picking $k$ items from $n$ items where arrangement matters. Formula: $\frac{n!}{(n-k)!}$
* **Combinations (Order Does Not Matter):** Picking $k$ items from $n$ items, ignoring arrangement. Formula: $\binom{n}{k} = \frac{n!}{k!(n-k)!}$
    * Note that this formula is the same as permutations, divided by the number of ways to order $k$ elements: $k!$

- **Fast Binomial Coefficients ($nCr$)**
    - Calculating $\binom{n}{k}$ naively is too slow.
    - **Intuition:** The formula for $\binom{n}{k}$ strictly uses factorials. We can precompute all factorials up to our constraint $N$ in $O(N)$ time.
        - Because we are ***dividing*** by $k!$ and $(n-k)!$, we must multiply by their modular inverses.
        - This would take $O(\log \text{MOD})$ time per query using `binpow()`, but we can precompute them as well for $O(1)$ per query.

- **The $O(N)$ Inverse Factorial Trick:** Since $k! = k \cdot (k-1)!$, it follows that the inverse is $\frac{1}{k!} = \frac{1}{k} \cdot \frac{1}{(k-1)!}$.
    - Thus we can generate all smaller inverse factorials as: `invFact[i] = invFact[i+1] * (i+1)`.

```cpp
const int mxn = 1e6 + 5;
long long fact[mxn], inv_fact[mxn];

void precompute() {
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < mxn; ++i) {
    fact[i] = mul(fact[i-1], i);
  }
  inv_fact[mxn-1] = mod_inv(fact[mxn-1]);
  for (int i = mxn-2; i >= 1; --i) {
    inv_fact[i] = mul(inv_fact[i+1], i+1);
  }
}

long long nPr(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fact[n], inv_fact[n-k]);
}

long long nCr(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fact[n], mul(inv_fact[k], inv_fact[n-k]));
}
```

### Principle of Inclusion-Exclusion (PIE)
- PIE is used when counting the size of the union of multiple overlapping sets.
- **Intuition:** If you want to count valid configurations satisfying multiple conditions, you often overcount. PIE states that you should:
    1. Add the individual counts.
    2. Subtract the pairwise intersections (you counted them twice).
    3. Add the triple intersections (you subtracted them entirely).
    4. Alternate this pattern for all subset intersections.

**Formula:** $|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$

**Implementation:** PIE is often implemented by iterating over all $2^k$ subsets using a [bitmask](bit-manipulation.md) (where $k$ is the number of conditions/sets, $k \le 20$). The number of set bits (`__builtin_popcount`) dictates whether we add or subtract.
```cpp
long long total_valid = 0, k = 3;
for (int mask = 1; mask < (1 << k); mask++) {
  int bits = __builtin_popcount(mask);
  long long res = compute_intersection(mask); // problem-specific logic
  if (bits % 2 == 1) {
    total_valid += res;
  } else {
    total_valid -= res;
  }
}
```

### 1. Catalan Numbers
- Catalan numbers represent the number of ways to recursively partition a structure.
- **Applications:** Number of valid bracket sequences of length $2n$, number of structurally distinct Binary Search Trees with $n$ nodes, number of ways to triangulate a convex polygon with $n+2$ sides.
- **Formula:** $C_n = \frac{1}{n+1} \binom{2n}{n}$

### 2. Cayley's Formula
- Used heavily when dealing with [Trees](trees.md).
- **Application:** The number of distinct labeled trees that can be formed using $n$ vertices.
- **Formula:** $n^{n-2}$

### 3. Burnside's Lemma
- Used for counting "distinct" colorings or arrangements of an object when rotations or reflections are considered equivalent (coloring a necklace or a cube).
- **Intuition:** The number of unique configurations is the **average number of fixed points** across all possible symmetries.
- **Formula:** $|X/G| = \frac{1}{|G|} \sum_{g \in G} |X^g|$
- *(Where $G$ is the group of symmetries, and $|X^g|$ is the number of configurations left unchanged by symmetry $g$.)*
