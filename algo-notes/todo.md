Majority of material coming from [codeforces blogs](https://codeforces.com/catalog) and [cp-algorithms](https://cp-algorithms.com/index.html)

- [x] **binary search**
    - [x] std::lower_bound and std::upper_bound
    - [x] ternary search (extrema of unimodal functions)

- [x] **two pointers & sliding window**
    - [x] variable vs. fixed-length windows
    - [x] subarrays with exactly/at most $k$ distinct elements

- [ ] **arrays & offline queries**
    - [ ] prefix sums (1D and 2D)
    - [ ] difference arrays
    - [ ] coordinate compression (needed for fenwick/segment trees when values are up to $10^9$)
    - [ ] line sweep (intervals)
    - [ ] mo's algorithm (standard square-root decomposition for offline range queries)

- [ ] **math & number theory**
    - [ ] modular arithmetic & modular inverse
    - [ ] binary exponentiation
    - [ ] matrix exponentiation (for O(log n) linear recurrences i.e. fibonacci)
    - [ ] extended euclidean algorithm
        - [ ] gcd/lcm
        - [ ] divisors
    - [ ] prime algorithms
        - [ ] prime divisor composition
    - [ ] standard sieve of eratosthenes
    - [ ] smallest prime factor sieve (for prime factorization)
    - [ ] combinatorics (precomputing factorials and inverses via fermat's little theorem)
    - [ ] inclusion exclusion
    - [ ] euler's totient function

- [ ] **dynamic programming**
    - [ ] approaching solutions (state definition, transitions, DAG representation)
        - [ ] compared with divide and conquer
    - [ ] top-down memoization vs bottom-up tabulation
    - [ ] classic problems: knapsack (0/1 and unbounded), LIS, LCS, edit distance, longest palindromic substring/subsequence
    - [ ] bitmask dp (subset traversals)
    - [ ] digit dp (counting numbers in a range with specific properties)
    - [ ] dp optimizations
    - [ ] divide and conquer optimization
    - [ ] convex hull trick

- [ ] **graphs & trees**
    - [ ] bfs/dfs
        - [ ] 0-1 BFS (deque for graphs with edge weights of only 0 and 1)
    - [ ] shortest path (dikjstra, floyd, bellman-ford)
        - [ ] multi-source versions
    - [ ] SCC (kosaraju's)
    - [ ] bridges and articulation points
    - [ ] 2-SAT (via SCCs)
    - [ ] eulerian path/circuit, hamiltonian path
    - [ ] topological ordering (kahn)
    - [ ] bipartite check / graph coloring
    - [ ] trees
        - [ ] binary lifting (lowest common ancestor)
        - [ ] mst (kruskals with dsu)
        - [ ] dsu on trees/sack (offline subtree queries)
    - [ ] network min/max flow (dinic's algorithm)

- [ ] **data structures**
    - [ ] disjoint set union (dsu)
    - [ ] segment tree
        - [ ] point update, range query
        - [ ] lazy propogation (range updates)
        - [ ] persistant segment trees (2d queries)
    - [ ] fenwick trees (simpler than segment tree, but less applicable)
    - [ ] sparse table (static idempotent range queries i.e. max/min/gcd)

- [ ] **strings**
    - [ ] string hashing (double polynomial rolling hash)
    - [ ] Z function/algorithm
    - [ ] trie (prefix tree)
    - [ ] suffix array
    - [ ] Aho–Corasick (multiple pattern matching)

- [ ] **bit manipulation**
    - [ ] subsets, masking, xor tricks
    - [ ] builtin popcount functions

- [ ] **game theory**
    - [ ] vocabulary
    - [ ] nim game basics
    - [ ] grundy numbers
    - [ ] sprague-grundy

- [x] **geometry**
    - [x] cross products, point orientation
    - [x] point inside a polygon test
    - [x] convex hull
    - ~~[ ] closest pair of points (divide and conquer)~~

- [ ] **search techniques**
    - [ ] meet in the middle (for subsets where $n=40$)
    - [ ] backtracking and pruning
