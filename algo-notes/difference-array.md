## Difference Arrays

> **TL;DR:** Inverse of [prefix sums](prefix-sum.md), allowing $O(1)$ range updates offline, applying them all in a single $O(N)$ pass at the end.
> **Note:** If we are solving an **online** problem where we have to interleave queries and updates, you must use a [lazy segment tree](segment-tree.md) or [fenwick tree](fenwick-tree.md)

- Given an array, you can process, in $O(1)$ time, queries in the form of:
  - Add a value $V$ to all elements in the range $[l,r]$
- After processing queries, we can do an $O(N)$ pass to output the final up-to-date array.

* $D[i]$ stores the ***difference*** between the current element and the previous element: $D[i] = A[i] - A[i-1]$
* To re-obtain the original array, we simply perform a prefix sum on the difference array $D$.
* Because of this, if we want to update a range, we can leverage how we compute the [prefix-sum](prefix-sum.md). Once we reach $l$, we want to include the updated $V$ value, and we want to keep including it until we leave $r$. Once we leave $r$, the prefix sum should no longer be tracking the $V$ contribution, so we can subtract it.
  * Add $V$ to $[l..r]$
  * $D[l] = D[l] + V$
  * $D[r+1] = D[r+1] - V$

| Index `i`                           | 0   | 1   | 2   | 3   | 4   | 5   |
| ----------------------------------- | --- | --- | --- | --- | --- | --- |
| **Original $A$**                    | 1   | 2   | 3   | 4   | 5   | 6   |
| **Diff Array $D$**                  | 1   | 1   | 1   | 1   | 1   | 1   |
| **Query: add 5 to elements [1..3]** |     |     |     |     |     |     |
| **Diff Array $D$**                  | 1   | 6   | 1   | 1   | -4  | 1   |
| **Reconstructed $A$**               | 1   | 7   | 8   | 9   | 5   | 6   |

**Note:** it is also common to simply initialize a difference array to zeros if we only care about the number of times an index was queried. This doesn't incorporate a pre-existing array, but still produces the same result as if we had an array $A$ filled with zeros.

```cpp
int n;
int a[n], d[n];

// std::adjacent_difference(a, a+n, d);
void build() {
  for (int i = 0; i < n; ++i) {
    d[i] = a[i] - (i > 0 ? a[i-1]: 0);
  }
}
void update(int l, int r, int v) {
  d[l] += v;
  if (r+1 < n) d[r+1] -= v;
}
void reconstruct() {
  for (int i = 0; i < n; i++) {
    a[i] = (i > 0 ? a[i-1]: 0) + d[i];
  }
}
```
