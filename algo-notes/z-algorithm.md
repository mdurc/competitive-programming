## Z-Algorithm/Z-Function

> **TL;DR:** fast $O(N)$ string algorithm used to compute the Z-array.
> **NOTE:** this is an intuitive alternative to KMP for pattern matching. By concatenating (`Pattern + $ + Text`) we can find pattern matches where `Z[i] = pattern.size()`.

- **Z-Array:**
    - `Z[i]` = length of the longest substring starting at `i` that is also a prefix of `S`.
    - `Z[i]` = longest common prefix between `S[0..N-1]` and `S[i..N-1]`.
    - `Z[0]` indicates `S[0] != S[i]`

- **Technique:**
    - Maintain an interval `[L, R]` such that `S[L..R]` is the rightmost substring that is also a prefix `S[0..R-L]`.
    - Given `[L, R]` and all Z-values up to `i-1`, we can compute `Z[i]` and the new `[L, R]`.

**Algorithm:** $O(N)$
1. ***if `i > R`:*** there doesn't exist a prefix-substring that starts before `i` and ends at or after `i`.
    - If such a prefix-substring did exist, the interval `[L, R]` would have been extended to include `i`.
    - Thus, we must create a **new range** `[L, R]` by comparing `S[0..]` to `S[i..]`, obtaining `Z[i]` along the way: `Z[i] = R-L+1`.
2. ***if `i <= R`:*** let `k = i-L`, where `S[k]` is the prefix-counterpart to `S[i]` (meaning `S[k] = S[i]`).
    - We know that `Z[i] >= min(Z[k], R-i+1)` because `S[i..]` matches `S[k..]` for at least `R-i+1 >= 1` characters (due to range `[L, R]`).
    - **if `Z[k] < R-i+1`:** `Z[k]` must stop strictly before length from `i` to `R`, thus `Z[i] = Z[k]`.
        - `[L, R]` only changes if there is a prefix-substring starting at `S[i]` that extends beyond R. Since this won't happen in this case, `[L, R]` is ***unchanged***.
    - **if `Z[k] >= R-i+1`:** it is possible that `S[0..]` will match `S[i..]` for more than `R-i+1` characters (*past position `R`*).
        - Thus, we must update `[L, R]` via `L = i`, and matching from `S[R+1..]` onward to obtain the new `R`.
        - This will also be computing `Z[i] = R-L+1` as before.

```cpp
std::vector<int> z_function(const std::string& s) {
  int n = (int)s.size();
  std::vector<int> z(n);
  z[0] = 0;
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i > r) {
      if (s[i] != s[0]) { z[i] = 0; continue; }
      l = i, r = i;
      // extend right border
      while (r+1 < n && s[r+1] == s[r-i+1]) ++r;
      z[i] = r - i + 1;
    } else if (i <= r) {
      int k = i - l;
      if (z[k] < r-i+1) {
        z[i] = z[k];
      } else if (z[k] >= r-i+1) {
        l = i;
        // extend right border
        while (r+1 < n && s[r+1] == s[r-i+1]) ++r;
        z[i] = r - i + 1;
      }
    }
  }
  return z;
}

// pattern matching with z_function:
std::vector<int> z_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> z = z_function(pattern + "$" + text);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  for (int i = psz+1; i < psz + tsz + 1; ++i) {
    if (z[i] == psz) res.push_back(i-(psz+1));
  }
  return res;
}
```

### Resources

* intution & implementation: https://codeforces.com/blog/entry/3107
