**Primary resources:** youtube videos (Errichto, WilliamFiset, AlgorithmsLive!, SecondThread), [codeforces blogs](https://codeforces.com/catalog), [cp-algorithms](https://cp-algorithms.com/index.html), and Guide to Competitive Programming by Antti Laaksonen

**Note:** most competitive programming problems don't just test your knowledge of algorithms; it tests your ability to make mathematical observations and reduce complex problems into simple ones. The majority of the problem solutions fall into the category of Ad-Hoc, Greedy, or Math. The most relevent areas to study are the following: ad-hoc, greedy, number theory, binary search, prefix sums/two pointers, dynamic programming, rolling hash, segment tree, disjoint set union.

**C++ Implementation Tricks**
- **Global primitive arrays**: `const int mxn = 2e5 + 5; int a[mxn]; int dp[mxn][100];`
  - automatically zero-initialized and allocated on the heap/BSS segment
    - `std::vector` can have significant re-allocation overhead. Best to reserve space.
- **Initialization:**
  - `std::memset`: set each byte to a certain value (setting values to 0 or -1)
    - `memset(dp, 0x3f, sizeof(dp))` will yield `0x3f3f3f3f` which is around 1e9, often used as infinity that won't overflow.
  - `std::fill`: initialize each index to a certain value (setting values that are not 0 or -1)
    - `fill(a, a+n, val)`
- **std Algorithms:**
  - `std::iota(begin, end, start_val)`: fills a range with sequentially increasing values
  - `std::count(begin, end, val)`: returns the frequency of val in the range
  - `std::accumulate(begin, end, 0LL)`: sums the elements in a range
  - `std::unique(begin, end)`: used heavily in coordinate compression. Moves all consecutive duplicate elements to the end of a container and returns an iterator to the new logical end. (Always sort the vector before calling unique).
- **Fast IO:**
  - disable synchronization between C and C++ standard streams and untie `cin` from `cout`
    ```cpp
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ```
  - favor using `"\n"` instead of `std::endl` which flushes the output buffer on every call. Only use `std::endl` in interactive problems.
- **Recursive Lambdas:**
  ```cpp
  auto dfs = [&](auto& dfs, int u, int p) -> void {
    for (int v : adj[u]) {
      if (v != p) dfs(dfs, v, u);
    }
  };
  dfs(dfs, 1, 0);
  ```
