## Master Theorem & Big-O Notation

> **TL;DR:** Big-O notation describes the asymptotic upper bound of an algorithm's time or space complexity as input size $N$ approaches infinity. The Master Theorem formulaic method to compute the time complexity of divide-and-conquer recurrences without expanding the recurrence tree manually.

### 1. Asymptotic Notation

* **Big-O ($O$):** Upper bound. The algorithm takes *at most* this amount of time (worst-case).
* **Big-Omega ($\Omega$):** Lower bound. The algorithm takes *at least* this amount of time (best-case).
* **Big-Theta ($\Theta$):** Tight bound. The upper and lower bounds are identical ($O = \Omega$).

* *Note:* $O(N)$ is commonly used interchangeably with $\Theta(N)$ to describe the exact worst-case scaling.

### 2. Computing Time Complexity

- When analyzing *iterative algorithms*, complexity is determined by counting primitive operations and applying two primary rules:
    1. **Drop Constants:** Constants do not affect the asymptotic growth rate.
        * $O(2N) \to O(N)$
        * $O(\frac{N}{2}) \to O(N)$
    2. **Drop Non-Dominant Terms:** Only the fastest-growing term dictates behavior as $N \to \infty$.
        * $O(N^2 + N + 1000) \to O(N^2)$
        * $O(N + \log N) \to O(N)$

* **Sequential (Addition):** Executing loops one after another adds their complexities.
    * An $O(N)$ loop followed by an $O(M)$ loop $\implies O(N + M)$.

* **Nested (Multiplication):** Loops placed inside one another multiply their complexities.
    * An $O(N)$ loop containing an $O(M)$ loop $\implies O(N \cdot M)$.

### 3. Common Time Complexities (Slowest to Fastest Growth)

* **$O(1)$ Constant:** Array indexing, hash map lookups, bitwise operations.
* **$O(\log N)$ Logarithmic:** [binary search](binary-search.md), traversing a balanced Binary Search Tree. The search space is reduced by a fraction at each step.
* **$O(N)$ Linear:** Traversing an array, [two pointers](two-pointers.md).
* **$O(N \log N)$ Linearithmic:** Comparison-based [sorting](sorting.md) (Merge Sort, Heap Sort), building a [segment tree](segment-tree.md).
* **$O(N^2)$ Quadratic:** Nested loops, naive 2D array traversal, Bubble Sort.
* **$O(2^N)$ Exponential:** Iterating over all subsets -- [bitmasking](bit-manipulation.md).
* **$O(N!)$ Factorial:** Iterating over all permutations.

### 4. The Master Theorem -- Solving Recurrence Relations

$T(N) = aT\left(\frac{N}{b}\right) + O(N^d)$
- $N$: Size of the current problem.
- $a$: Number of subproblems in the recursion ($a \ge 1$).
- $b$: Factor by which the subproblem size is reduced ($b > 1$).
- $O(N^d)$: Time spent doing non-recursive work (e.g., dividing the problem or merging results).

**Expanding the Recurrence Tree:**
* $T(n) = aT(\frac{n}{b}) + O(n^d)$
    * After expanding $T(\frac{n}{b})$ in this formula $k$ times:
        * $T(n) = a^k T(\frac{n}{b^k}) + a^{k-1} O\left(\left(\frac{n}{b^{k-1}}\right)^d\right) + a^{k-2} O\left(\left(\frac{n}{b^{k-2}}\right)^d\right) + \dots + a O\left(\left(\frac{n}{b}\right)^d\right) + O(n^d)$
    * Extracting $b^x$ from each big-O:
        * $T(n) = a^k T(\frac{n}{b^k}) + \left(\frac{a}{b^d}\right)^{k-1} O(n^d) + \left(\frac{a}{b^d}\right)^{k-2} O(n^d) + \dots + \left(\frac{a}{b^d}\right) O(n^d) + O(n^d)$
    * Let $q = \frac{a}{b^d}$, and since $\frac{n}{b^k} = 1$, we know $k = \log_b n$
        * $T(n) = a^{\log_b n} + (q^{k-1} + q^{k-2} + \dots + q^2 + q^1 + 1) O(n^d)$
    * Applying the geometric series formula and noting that $a^{\log_b n} \Leftrightarrow n^{\log_b a}$:
        * $T(n) = n^{\log_b a} + \left(\frac{1-q^k}{1-q}\right) O(n^d)$

**3 cases: $q > 1, q < 1, q = 1$**
1. **$q > 1 : d < \log_b a$**
    * $\left(\frac{1-q^k}{1-q}\right)$ has a negative denominator, thus the numerator is $q^k - 1$
        * $q^k \Leftrightarrow \left(\frac{a}{b^d}\right)^k \Leftrightarrow \left(\frac{a}{b^d}\right)^{\log_b n} \Leftrightarrow n^{\log_b(\frac{a}{b^d})}$
    * Thus:
        * $T(n) = n^{\log_b a} + O(n^{\log_b(\frac{a}{b^d})} n^d) = n^{\log_b a} + O(n^{d + \log_b(\frac{a}{b^d})})$
        * $T(n) = n^{\log_b a} + O(n^{\log_b b^d + \log_b(\frac{a}{b^d})}) = n^{\log_b a} + O(n^{\log_b a})$
        * $T(n) = \mathbf{O(n^{\log_b a})}$
2 **$q < 1 : d > \log_b a$**
    * $1$ is the positive value in numerator: $1 - q^k$
    * $T(n) = n^{\log_b a} + O(n^d) = \mathbf{O(n^d)}$
3. **$q = 1 : d = \log_b a$**
    * $q^{k-1} + q^{k-2} + \dots + q^2 + q^1 + 1$ evaluates to $1 + 1 + \dots + 1 + 1 \dots$ which equals $k$
    * $T(n) = n^{\log_b a} + kO(n^d)$
    * $T(n) = n^{\log_b a} + (\log_b n)O(n^d)$
    * $T(n) = n^d + O(n^d \log_b n) = \mathbf{O(n^d \log_b n)}$

**Summary:**

$$T(n) = aT\left(\frac{n}{b}\right) + O(n^d)$$
$$
T(n)=
\begin{cases}
O(n^{\log_b a}) & d < \log_b a \\
O(n^d) & d > \log_b a \\
O(n^d \log n) & d = \log_b a
\end{cases}
\qquad
(a>0, b>1, d\ge0)
$$


### 5. Examples
* **[Merge Sort](sorting.md)**
    * **Algorithm:** Divides the array into $2$ halves, recursively sorts them, and then merges the two halves in $O(N)$ time.
    * **Recurrence:** $T(N) = 2T(\frac{N}{2}) + O(N)$
    * **Master Theorem Analysis:**
    * $a = 2$, $b = 2$, $d = 1$
    * Compute: $\log_b a = \log_2 2 = 1$
    * Compare: $d = \log_b a$ ($1 = 1$)
    * **Verdict:** Case 2 (Balanced Work). $T(N) = \Theta(N^1 \log N) = \Theta(N \log N)$

* **[Binary Search](binary-search.md)**
    * **Algorithm:** Looks at the midpoint $O(1)$, and conditionally recurses on exactly $1$ half of the array.
    * **Recurrence:** $T(N) = 1T(\frac{N}{2}) + O(1)$
    * **Master Theorem Analysis:**
    * $a = 1$, $b = 2$, $d = 0$ (since $O(1) = O(N^0)$)
    * Compute: $\log_b a = \log_2 1 = 0$
    * Compare: $d = \log_b a$ ($0 = 0$)
    * **Verdict:** Case 2 (Balanced Work). $T(N) = \Theta(N^0 \log N) = \Theta(\log N)$

### 6. Limitations
- The Master Theorem *cannot* be used if:
    1. $T(N)$ is not monotonic (e.g., $T(N) = \sin(N)$).
    2. $f(N)$ is not a polynomial (e.g., $f(N) = 2^N$).
    3. The problem size is not reduced by a constant factor $b$ (e.g., $T(N) = T(N-1) + O(1)$).
    4. The number of subproblems varies based on state rather than remaining constant $a$.
