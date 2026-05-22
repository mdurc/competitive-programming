## Ternary Search

> **TL;DR:** Locates the maximum or minimum (extrema) of a unimodal function within a given range in $O(\log N)$ time by repeatedly dividing the search space into thirds.

### 1. Intuition

* **Problem:** [Binary search](binary-search.md) requires a monotonic (always increasing or always decreasing) search space. If a function increases to a peak and then decreases (or decreases to a valley and then increases), binary search cannot be directly applied to find that peak/valley.
* **Insight:** This type of curve is called a **unimodal function**. It has exactly one extreme point (maximum or minimum). If we pick two points $m_1$ and $m_2$ inside our search space $[l, r]$ such that $l < m_1 < m_2 < r$, we can evaluate $f(m_1)$ and $f(m_2)$.
* **The Elimination:** Suppose we are looking for a **maximum**.
  * If $f(m_1) < f(m_2)$, the peak cannot be in the left third. Discard the segment $[l, m_1]$ by setting $l = m_1$.
  * If $f(m_1) > f(m_2)$, the peak cannot be in the right third. Discard $[m_2, r]$ by setting $r = m_2$.
  * If $f(m_1) = f(m_2)$, the peak must be between them. Set $l = m_1$ and $r = m_2$.

### 2. Implementation

**Floating Point Ternary Search:** incorporate an absolute error

```cpp
double ternary_search(double l, double r) {
  double eps = 1e-9;        //error limit
  while (r - l > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  return f(l);
}
```

**Integer Ternary Search:** When dealing with integers, the midpoints will often evaluate to the same integer. To avoid this, we stop the ternary search when the window size is small ($\le 3$) and do a linear scan.
```cpp
// Finding the MAXIMUM of a discrete unimodal function f(x)
int l = 0, r = 1e9;
while (r - l > 2) { // > 3 elements
  int m1 = l + (r - l) / 3;
  int m2 = r - (r - l) / 3;
  if (f(m1) < f(m2)) {
    l = m1;
  } else {
    r = m2;
  }
}
// linear scan
int max_val = f(l), best_x = l;
for (int i = l+1; i <= r; i++) {
  if (f(i) > max_val) {
    max_val = f(i);
    best_x = i;
  }
}
return best_x;
```

### 3. Resources

* https://cp-algorithms.com/num_methods/ternary_search.html
