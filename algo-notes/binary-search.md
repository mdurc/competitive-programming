## Binary Search & Binary Search on Answer

> **TL;DR:** Locates elements or decision boundaries in a monotonic (ordered) search space in $O(\log N)$ time. Generally transforms an optimization problem into a "yes/no" decision problem.

* A linear scan will take $O(N)$ time. Too slow for $N \ge 10^9$.

- If a search space is **monotonic** it means that a sequence of values or conditions move strictly in one direction without ever reversing.
  - *Monotonically increasing:* values only go up or the same: $1, 2, 2, 4, 7$
  - *Monotonically decreasing:* values only go down or the same: $7, 4, 2, 2, 1$
- Monotonic search spaces allow us to eliminate half of the remaining possibilities at every step.
  - This allows us to perform queries at $O(\log N)$ time.
- This is the traditional binary search implementation (locate a value within a sorted array), however it can be generalized into BSTA.

* **Binary Search on Answer (BSTA):** instead of searching for a value, we search over the *range of possible answers* to our problem. If the problem asks to "maximize the minimum" or "minimize the maximum", we guess an answer `mid`, and write a greedy/ad-hoc checker function `cond(mid)` to see if `mid` is achievable.
  - This condition evaluation function transforms the problem into a monotonic boolean search space `[T T T F F]` or `[F F F T T]`, allowing us to binary search the boundary where the condition flips.


### Implementation
**Standard library functions:**
```cpp
// both lower_bound and upper_bound return an iterator; a.end() if no element is found
std::lower_bound(a.begin(), a.end(), 5); // first element >= 5
std::upper_bound(a.begin(), a.end(), 5); // first element > 5

// boolean check for an element
std::is_sorted(a.begin(), a.end()); // binary search requires a sorted array
std::binary_search(a.begin(), a.end(), 5); // true if 5 exists in a
```

**Binary search template:** the most important concept to understand is how the midpoint is picked, and which pointer we need to update in order to progress and avoid an infinite loop. Remember to consider overflow when computing the midpoint, and to consider left or right leaning midpoint to avoid infinite loops.
```cpp
// Find the FIRST T in: FFFFFTTTTTTT
int l = 0, r = n-1; // both l and r are IN the search space
while (l < r) {
  int mid = l + (r - l) / 2; // left-leaning middle (for an even-length range)
  if (cond(mid)) {
    r = mid;      // 'mid' is true, so the answer is 'mid' or something before it
  } else {
    l = mid + 1;  // 'mid' is false, so the answer must be strictly after 'mid'
  }
}
return l;

// Find the LAST T in: TTTTTTFFFFFF
int l = 0, r = n-1; // both l and r are IN the search space
while (l < r) {
  int mid = l + (r - l + 1) / 2; // right-leaning middle to avoid infinite loop
  if (cond(mid)) {
    l = mid;      // 'mid' is true, so the answer is 'mid' or something after it
  } else {
    r = mid - 1;  // 'mid' is false, so the answer must be strictly before 'mid'
  }
}
return l; // l == r
```

### Resources
* https://leetcode.com/discuss/post/786126/python-powerful-ultimate-binary-search-t-rwv8/
* https://www.youtube.com/watch?v=GU7DpgHINWQ
