## Binary Search & Binary Search on Answer

> **TL;DR:** Locates elements or decision boundaries in a monotonic (ordered) search space in $O(\log N)$ time. Generally transforms an optimization problem into a "yes/no" decision problem.

### 1. Intuition
* **Problem:** A linear scan will take $O(N)$ time. Much too slow for a large search space ($10^9$ or $10^18$).
* **Insight:** If a search space is **monotonic**, we can eliminate half of the remaining possibilities at every step. Monotonicity means the condition we are checking looks like a sequence of `false` followed by `true` (`FFFFFTTTTT`), or vice-versa (`TTTTTFFFFF`). This often comes in the form of requiring the input array to be **sorted**.
* **Binary Search on Answer (BSTA):** Instead of searching for a value in an array, we binary search over the *possible range of answers*. If the problem asks to "maximize the minimum" or "minimize the maximum", we guess an answer `mid`, and write a greedy/ad-hoc checker function `cond(mid)` to see if `mid` is achievable.

### 2. Implementation
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

### 3. Resources
* https://leetcode.com/discuss/post/786126/python-powerful-ultimate-binary-search-t-rwv8/
* https://www.youtube.com/watch?v=GU7DpgHINWQ
