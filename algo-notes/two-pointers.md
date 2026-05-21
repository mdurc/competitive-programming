## Two Pointers & Sliding Window

> **TL;DR:** Optimizes $O(N^2)$ nested loops over arrays into a single $O(N)$ pass by maintaining two indices (pointers) that only ever move in one direction.

### 1. Intuition

* **Problem:** Finding a valid subarray or a pair of elements that satisfy a condition naively takes $O(N^2)$ time.
* **Insight:** If the condition we are checking is **monotonic** (e.g., adding elements to a subarray strictly increases its sum, or removing elements strictly decreases it), we can avoid redundant work. By moving a left pointer `l` and a right pointer `r` forward without ever resetting them back to zero, each pointer traverses the array at most once, reducing the time complexity to $O(N)$.
* **Sliding Window vs. Two Pointers:** "Two Pointers" often refers to pointers starting at opposite ends and moving toward the center (e.g., finding pairs in a sorted array). "Sliding Window" typically has both pointers starting at the beginning, moving in the same direction to maintain a contiguous valid segment, usually of fixed size.

### 2. Implementation

**Sliding Window (variable length):** finding the longest contiguous subarray that satisfies a condition (sum $\le S$, or at most $K$ distinct elements). Expand `r` to add elements, and shrink `l` iteratively only when the window becomes invalid.

```cpp
int l = 0, ans = 0;
for (int r = 0; r < n; r++) {
  // add a[r] to the window state
  while (l <= r && /* window condition is invalid */) {
    // remove a[l] from the window state
    l++;
  }
  ans = std::max(ans, r-l+1); 
}
```

**Two Pointers (opposite ends):** often to find two elements that sum to a specific target $X$.
```cpp
int l = 0, r = n - 1;
// assuming a sorted array:
while (l < r) {
  int sum = a[l] + a[r];
  if (sum == target) {
    break; 
  } else if (sum < target) {
    l++; // we need a larger sum, move left pointer up
  } else {
    r--; // we need a smaller sum, move right pointer down
  }
}

```
