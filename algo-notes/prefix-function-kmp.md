## Prefix Function & Knuth-Morris-Pratt (KMP)

> **TL;DR:** An $O(N)$ string matching algorithm that avoids redundant comparisons by precomputing a "failure" array. The core of KMP is the **Prefix Function** ($\pi$ array), which is a 1D state machine.

### Prefix Function
* **Definition:** `lps[i]` is the length of the **longest proper prefix** of `S[0..i]` that is a **suffix** of `S[0..i]`.
    * A *proper* prefix of a string is a prefix that is strictly shorter than the string itself.
    * This is also called the $\pi$ array.
* `lps[0] = 0` always, because a string of length 1 has no proper prefix.

* **Example:** $S =$ `"abcabcd"`
    * $i=0: \text{lps}[0] = 0$ (`"a"`)
    * $i=1: \text{lps}[1] = 0$ (`"ab"`)
    * $i=2: \text{lps}[2] = 0$ (`"abc"`)
    * $i=3: \text{lps}[3] = 1$ (`"abca"`: prefix `"a"` matches suffix `"a"`)
    * $i=4: \text{lps}[4] = 2$ (`"abcab"`: prefix `"ab"` matches suffix `"ab"`)
    * $i=5: \text{lps}[5] = 3$ (`"abcabc"`: prefix `"abc"` matches suffix `"abc"`)
    * $i=6: \text{lps}[6] = 0$ (`"abcabcd"`: mismatch on `'d'`)

**Algorithm/Implementation ([two pointers](two-pointers.md))**
* Iterate through the string maintaining a variable $L$, representing the length of the current matching prefix ($L = \text{lps}[R-1]$).
* When comparing the next character $S[L]$ against the expected character $S[R]$:
    * **Match ($S[L] == S[R]$):** The matching prefix length simply increases by 1. We set $\text{lps}[R] = L + 1$.
    * **Mismatch ($S[L] \neq S[R]$):** There might be a shorter prefix that still matches. We find the next longest fallback using the $\text{lps}$ array: $L = \text{lps}[L-1]$. We repeat this fallback until we find a match or $L$ hits $0$.

[prefix-function.pdf](attachments/prefix-function.pdf)
![](attachments/prefix-function.pdf)

```cpp
std::vector<int> prefix_function(const std::string& s) {
  int n = (int)s.size();
  std::vector<int> lps(n);
  lps[0] = 0;
  int l = 0, r = 1;
  while (r < n) {
    if (s[l] == s[r]) {
      lps[r] = l+1;
      ++l, ++r;
    } else {
      if (l == 0) ++r;
      else l = lps[l-1];
    }
  }
  return lps;
}
```

### KMP Pattern Matching
- To find all occurrences of a `pattern` within a `text` in $O(|P| + |T|)$ time, we have two standard approaches.

1. **Concatenation (nearly identical to [Z-Algorithm](z-algorithm.md)'s pattern matching technique)**
    - The only difference is that `lps[i] == psz` indicates that `i` is the *end* of the pattern in the `text`-string, and not the *start* as it is for the Z-algorithm.
```cpp
// return indices of text that start a substring that matches pattern
std::vector<int> prefix_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> lps = prefix_function(pattern + "$" + text);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  for (int i = psz+1; i < psz + tsz + 1; ++i) {
    // 0-based starting index in text (i - (psz-1) - (psz+1))
    if (lps[i] == psz) res.push_back(i - 2 * psz);
  }
  return res;
}
```

2. **State Machine (KMP)**
    * Implementation is very similar to the LPS construction algorithm. But there are some key differences:
        * LPS compares a single string against *itself* (`s[l] == s[r]`), but KMP compares a pattern against text (`pattern[l] == text[r]`).
        * LPS starts at `r = 1`, skipping index `0` because it is looking for *proper* prefixes (length 1 cannot have any proper prefixes). In KMP, we start at `r = 0` because it is possible that `pattern[0] != text[0]`.
        * LPS builds the array until `r` reaches the end of the string, where `l` will never reach the full string size. In KMP, we include a check for when we find a prefix-suffix length (`L`) equal to the pattern size (`psz`). When this happens, we can extract the starting index in the `text` string where the suffix begins (where `suffix = pattern`).
            * In KMP, we also have to manually perform a single-character mismatch (fall back using the LPS array) so that we can continue finding pattern-matches that may be overlapping one another, even if the last character was a correct final match.
```cpp
// return indices of text that start a substring that matches pattern
std::vector<int> kmp_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> lps = prefix_function(pattern);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  // LPS construction algorithm but with pattern[l], text[r]
  int l = 0, r = 0;
  while (r < tsz) {
    if (pattern[l] == text[r]) {
      ++l;
      ++r;
      if (l == psz) {
        res.push_back(r-l);
        // we reached full full prefix length, go back to the last prefix-suffix to keep searching
        l = lps[l-1];
      }
    } else {
      if (l == 0) ++r;
      else l = lps[l-1];
    }
  }
  return res;
}
```

### Resources
* visualization and implementation: https://www.youtube.com/watch?v=q4_90fOoS-s
