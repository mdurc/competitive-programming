> These problems cover common techniques and ideas within [dynamic programming](dynamic-programming.md) solutions. Often times a solution will be some variation of these.

### 1. Knapsack Problems
The Knapsack problem asks you to select a subset of items to maximize total value without exceeding a strict weight capacity.

**0/1 Knapsack (items can be used at most once)**
```cpp
/*
Definition:
  - dp[i][w]: maximum total value of a subset of items within a total weight of w, when considering items[0..i]
Recurrence:
  - we can either skip the current item, or take the current item
  - dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + val[i])
    - i depends on i-1: small to big
    - w depends on w-weight[i]: small to big
  - Base Case:
    - dp[0][w] = val[0]
      - where w is from: [weight[0]..W]
Bounds:
  - i: [0..n-1]
  - w: [0..W]
*/
int knapsack_01(int W, const std::vector<int>& weight, const std::vector<int>& val) {
  int n = (int)val.size();

#ifdef UNOPTIMIZED
  std::vector dp(n, std::vector<int>(W+1, 0));
  for (int w = weight[0]; w <= W; ++w) dp[0][w] = val[0];
  for (int i = 1; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      int skip = dp[i-1][w];
      int take = (w-weight[i] >= 0 ? dp[i-1][w-weight[i]] + val[i]: 0);
      dp[i][w] = std::max(skip, take);
    }
  }
  return dp[n-1][W];
#else
  // space optimization (note that we must iterate backwards in the inner loop to avoid picking the same item multiple times).
  // - generally we should simply stick to the unoptimized order for the intuition before optimizing.
  std::vector<int> dp(W+1, 0);
  for (int i = 0; i < n; ++i) {
    for (int w = W; w >= weight[i]; --w) {
      int skip = dp[w];
      int take = dp[w-weight[i]] + val[i];
      dp[w] = std::max(skip, take);
    }
  }
  return dp[W];
#endif
}
```

**Unbounded Knapsack (items can be used infinitely)**
- The state definition and transition are identical, but the recurrence (and base case) changes.
```cpp
/*
Recurrence:
  - we can either skip the current item, or take the current item
    - after taking, we still have the option to take it again, multiple times
    - in the take operation, we stay on i, instead of dp[i-1][w-weight[i]]
  - dp[i][w] = max(dp[i-1][w], dp[i][w-weight[i]] + val[i])
    - i depends on i-1: small to big
    - w depends on w-weight[i]: small to big
  - Base Case:
    - dp[0][w] = (w / weight[0]) * val[0];
      - where w is from: [weight[0]..W]
      - we want to include this item as much as possible within the weight constraint
*/
int knapsack_unbounded(int W, const std::vector<int>& weight, const std::vector<int>& val) {
  int n = (int)val.size();

#ifdef UNOPTIMIZED
  std::vector dp(n, std::vector<int>(W+1, 0));
  for (int w = weight[0]; w <= W; ++w) dp[0][w] = (w / weight[0]) * val[0];
  for (int i = 1; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      int skip = dp[i-1][w];
      int take = (w-weight[i] >= 0 ? dp[i][w-weight[i]] + val[i]: 0);
      dp[i][w] = std::max(skip, take);
    }
  }
  return dp[n-1][W];
#else
  // space optimization (iterate forwards to allow picking the same items multiple times).
  std::vector<int> dp(W+1, 0);
  for (int i = 0; i < n; ++i) {
    for (int w = weight[i]; w <= W; ++w) {
      int skip = dp[w];
      int take = dp[w-weight[i]] + val[i];
      dp[w] = std::max(skip, take);
    }
  }
  return dp[W];
#endif
}
```

### 2. Longest Increasing Subsequence (LIS)

Given an array, find the length of the longest subsequence where every element is strictly greater than the previous.

```cpp
/*
Definition:
  - dp[i]: length of the longest increasing subsequence ending at index i
Recurrence:
  - i is either:
    - a part of the current increasing subsequence from some subsequence ending at [0..i-1]
    - the start of a new increasing subsequence
  - Base Case:
    - dp[i] = 1
Bounds:
  - i: [0..n-1]
*/
int LIS(const std::vector<int>& a, int n) {
  std::vector<int> dp(n);
  for (int i = 0; i < n; ++i) dp[i] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i-1; ++j) {
      if (a[i] >= a[j]) dp[i] = std::max(dp[i], dp[j] + 1);
    }
  }
  return *std::max_element(dp.begin(), dp.end());
}
```

### 3. Longest Common Subsequence (LCS)

Given two strings (or arrays), find the length of the longest subsequence present in both.

```cpp
/*
Definition:
  - dp[i][j]: length of the longest common subsequence considering a[0..i], b[0..j]
Recurrence:
  - if a[i] and b[j] match, extend the sequence: dp[i][j] = dp[i-1][j-1] + 1;
  - otherwise, we must skip either a or b: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
  - i depends on i-1: small to big
  - j depends on j-1: small to big
Bounds:
  - i: [0..a.size()-1]
  - j: [0..b.size()-1]
*/
int LCS(const std::string& a, const std::string& b) {
  int n = a.size(), m = b.size();
  // we will use 1-based indexing
  std::vector dp(n+1, std::vector<int>(m+1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      // accessing a[i] will actually be a[i-1] due to 1-indexing
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[n][m];
}
```

---

## 4. Edit Distance (Levenshtein Distance)

Find the minimum number of operations (insert, delete, or replace) required to transform string `a` into string `b`.

```cpp
/*
Definition:
  - dp[i][j]: minimum number of operations to convert a[0..i-1] to b[0..j-1]
Recurrence:
  - if characters match (a[i-1] == b[j-1]), no new operation needed:
    - dp[i][j] = dp[i-1][j-1]
  - otherwise, we take the minimum of 3 possible operations and add 1:
    - Insert: dp[i][j-1] (conceptually adding b[j-1] to a)
    - Delete: dp[i-1][j] (conceptually removing a[i-1] from a)
    - Replace: dp[i-1][j-1] (conceptually swapping a[i-1] to b[j-1])
    - dp[i][j] = 1 + min(Insert, Delete, Replace)
  - i depends on i-1: small to big
  - j depends on j-1: small to big
Base Case:
  - dp[i][0] = i (converting length i string to empty string takes i deletions)
  - dp[0][j] = j (converting empty string to length j string takes j insertions)
Bounds:
  - i: [0..n]
  - j: [0..m]
*/
int minDistance(const std::string& a, const std::string& b) {
  int n = a.size(), m = b.size();
  std::vector dp(n + 1, std::vector<int>(m+1, 0));
  for (int i = 0; i <= n; ++i) dp[i][0] = i;
  for (int j = 0; j <= m; ++j) dp[0][j] = j;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        int del = dp[i-1][j];
        int ins = dp[i][j-1];
        int rep = dp[i-1][j-1];
        dp[i][j] = 1 + std::min({del, ins, rep});
      }
    }
  }
  return dp[n][m];
}
```

## 5. Interval DP: Longest Palindromic Subsequence

When a problem asks about properties defined by the boundaries of a sequence, the state typically transitions by shrinking the interval. This is known as **Interval DP**.
- Find the length of the longest palindromic subsequence in a string `s`.

```cpp
/*
Definition:
  - dp[i][j]: length of the longest palindromic subsequence within the substring s[i..j]
Recurrence:
  - if the boundary characters match (s[i] == s[j]), they wrap the inner palindrome:
    - dp[i][j] = dp[i+1][j-1] + 2
  - otherwise, we take the best palindrome by skipping either the left or right character:
    - dp[i][j] = max(dp[i+1][j], dp[i][j-1])
  - i depends on i+1: big to small (must iterate backwards)
  - j depends on j-1: small to big
Base Case:
  - dp[i][i] = 1 (every single character is a palindrome of length 1)
Bounds:
  - i: [n-1 down to 0]
  - j: [i up to n-1]
*/
int longestPalindromeSubseq(const std::string& s) {
  int n = s.size();
  std::vector dp(n, std::vector<int>(n, 0));
  for (int i = n-1; i >= 0; --i) {
    dp[i][i] = 1; // base case
    for (int j = i+1; j < n; ++j) {
      if (s[i] == s[j]) {
        dp[i][j] = dp[i+1][j-1] + 2;
      } else {
        int skip_left = dp[i+1][j];
        int skip_right = dp[i][j-1];
        dp[i][j] = std::max(skip_left, skip_right);
      }
    }
  }
  return dp[0][n-1];
}
```
