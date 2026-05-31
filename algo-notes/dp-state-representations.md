## DP State Spaces

When a problem's state cannot be easily represented by a simple index, we must use another construct.
- Two of the most common state representations are **Bitmask DP** and **Digit DP**.

### Bitmask DP
Used to identify an optimal permuation, subset, or path.
- We can represent any subset of $N$ items as an integer from $0$ to $2^N - 1$, where the $i$-th bit is $1$ if the $i$-th item is in the subset, and $0$ otherwise.
    - This allows us to use an integer as an index in our DP array.
    - See [bit subsets](bit-manipulation.md).

**Application: Traveling Salesperson Problem (TSP) / Hamiltonian Path**
- Finding the shortest path that visits every node exactly once.
    - A naive permutation search takes $O(N!)$.
    - Bitmask DP takes $O(N^2 2^N)$.

```cpp
/*
Definition:
  - dp[mask][u]: minimum cost to visit the exact subset of nodes represented by bits in 'mask', currently ending at node 'u'
Recurrence:
  - To be at 'u' with 'mask', we must have transitioned from some previous node 'v' in the state exactly one step in the past
  - prev_mask = mask ^ (1 << u)
  - dp[mask][u] = min(dp[mask][u], dp[prev_mask][v] + dist[v][u]) for all valid 'v'
  - mask depends on prev_mask: small to big
Base Case:
  - dp[1 << start][start] = 0 (cost to be at start node with only start visited is 0)
Bounds:
  - mask: [1 .. (1<<n)-1]
  - u, v: [0 .. n-1]
*/
const int INF = 1e9;
int min_hamiltonian_path(int n, const std::vector<std::vector<int>>& dist) {
  std::vector dp(1 << n, std::vector<int>(n, INF));
  dp[1][0] = 0; // base case at node 0 (1 << 0)
  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int u = 0; u < n; ++u) {
      // skip 'u' if it is not in the current subset
      if (!(mask & (1 << u))) continue; 
      int prev_mask = mask ^ (1 << u); // subset before visiting 'u'
      for (int v = 0; v < n; ++v) {
        // skip 'v' if it is not in the previous subset
        if (!(prev_mask & (1 << v))) continue; 
        dp[mask][u] = std::min(dp[mask][u], dp[prev_mask][v] + dist[v][u]);
      }
    }
  }
  // minimum cost to visit all nodes (mask is all 1s) ending at ANY node
  int full_mask = (1 << n) - 1;
  return *std::min_element(dp[full_mask].begin(), dp[full_mask].end());
}
```

### Digit DP

Digit DP is used when a problem asks you to count the number of integers within a large range $[L, R]$ that satisfy a specific property (e.g., "the sum of the digits is $K$" or "no two adjacent digits are the same").

**Prefix Subtraction Trick:**
- Instead of trying to solve for the exact range $[L, R]$ directly. Write a function `solve(X)` that counts the valid numbers in the range $[0, X]$.
- The answer for $[L, R]$ is guaranteed to be `solve(R) - solve(L - 1)`.

**State Variables:**
1. `idx`: The current digit position we are placing (from left to right).
2. `tight`: A boolean flag. If `true`, the prefix we have built so far is *exactly equal* to the prefix of our upper bound limit. This restricts the maximum digit we can place next.
3. `prop`: The problem-specific property we are tracking (e.g., `sum`, `prev_digit`, `is_leading_zero`).

**The `tight` Logic:** If our upper limit is $532$, and we are placing the second digit:
* If our first digit is $4$, `tight` is false. We can place any digit $0-9$.
* If our first digit is $5$, `tight` is true. We can only place digits $0-3$.

```cpp
/*
Definition:
  - dp[idx][tight][prop]: number of valid suffixes starting from 'idx', given the current 'tight' restriction and accumulated 'prop'
Recurrence:
  - Try placing every valid digit 'd' from 0 up to 'limit'
  - limit = tight ? (R_str[idx] - '0') : 9
  - new_tight = tight && (d == limit)
  - dp[idx][tight][prop] = sum( solve(idx + 1, new_tight, prop + d) )
Base Case:
  - if idx == R_str.length(), return 1 if 'prop' satisfies the target condition, else 0
Bounds:
  - idx: [0 .. R_str.length()-1]
  - tight: [0, 1]
  - prop: problem specific (e.g., [0 .. 200] for digit sums)
*/
std::string R_str; 
int memo[20][2][200]; // [idx][tight][sum_of_digits]

long long solve(int idx, bool tight, int sum, int target_sum) {
  // base case: placed all digits
  if (idx == R_str.length()) {
    return sum == target_sum ? 1 : 0;
  }
  
  // check cache
  if (memo[idx][tight][sum] != -1) {
    return memo[idx][tight][sum];
  }
  
  // determine upper bound for the current digit
  int limit = tight ? (R_str[idx] - '0') : 9;
  long long ans = 0;
  
  // state transitions
  for (int d = 0; d <= limit; ++d) {
    // the next state is only tight if it was ALREADY tight, AND we placed the maximum allowed digit
    bool new_tight = tight && (d == limit);
    ans += solve(idx + 1, new_tight, sum + d, target_sum);
  }
  
  return memo[idx][tight][sum] = ans;
}
```

> Note on **Leading Zeros:** For many digit properties (like counting specific digits or tracking adjacent matches), you must add an `is_leading_zero` boolean to your state.
- The number `005` is just $5$. If you are tracking "number of zero digits," you do not want to count the structural padding zeros. If `is_leading_zero` is true and you place a $0$, it should not increment your property counter, and the next state remains a leading zero state.
