Majority of material coming from [codeforces blogs](https://codeforces.com/catalog) and [cp-algorithms](https://cp-algorithms.com/index.html)

- [x] **binary search**
    - [x] std::lower_bound and std::upper_bound
    - [x] ternary search (extrema of unimodal functions)

- [x] **two pointers & sliding window**
    - [x] variable vs. fixed-length windows
    - [x] subarrays with exactly/at most $k$ distinct elements

- [x] **arrays & offline queries**
    - [x] prefix sums (1D and 2D)
    - [x] difference arrays
    - [x] coordinate compression (needed for fenwick/segment trees when values are up to $10^9$)
    - [x] line sweep (intervals)
    - [x] mo's algorithm (standard square-root decomposition for offline range queries)

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
    - [ ] basic graph terminology/representations
        - [ ] cycle detection
    - [ ] bfs/dfs
        - [ ] 0-1 BFS (deque for graphs with edge weights of only 0 and 1)
    - [ ] shortest paths (dikjstra, floyd, bellman-ford)
        - [ ] multi-source versions
    - [ ] SCC (kosaraju's)
        - [ ] 2-SAT (via SCCs)
    - [ ] bridges and articulation points
    - [ ] eulerian path/circuit, hamiltonian path
    - [ ] directed acyclic graphs
        - [ ] topological ordering
    - [ ] bipartite check / graph coloring
    - [ ] trees
        - [ ] binary lifting (lowest common ancestor)
        - [ ] mst (kruskals with dsu)
        - [ ] dsu on trees/sack (offline subtree queries)
    - [ ] network min/max flow (dinic's algorithm)

- [x] **data structures**
    - [x] disjoint set union (dsu)
    - [x] segment tree
        - [x] point update, range query
        - [x] lazy propogation (range updates)
        - ~~[ ] persistant segment trees (2d queries)~~
    - [x] fenwick trees (simpler than segment tree, but less applicable)
    - [x] sparse table (static idempotent range queries i.e. max/min/gcd)

- [x] **strings**
    - [x] string hashing (double polynomial rolling hash)
    - [x] suffix array
    - [x] Z-Algorithm
    - [ ] trie (prefix tree)
    - [ ] Aho–Corasick (multiple pattern matching)

- [x] **bit manipulation**
    - [x] subsets, masking, xor tricks
    - [x] builtin popcount functions

- [x] **game theory**
    - [x] vocabulary
    - [x] nim game basics
    - [x] grundy numbers
    - [x] sprague-grundy

- [x] **geometry**
    - [x] cross products, point orientation
    - [x] point inside a polygon test
    - [x] convex hull
    - ~~[ ] closest pair of points (divide and conquer)~~

- [ ] **Master theorem and Big-O**

- [ ] **Linear Programming**

- [ ] **search techniques**
    - [ ] subsets and permutations
    - [ ] backtracking and pruning
    - [ ] meet in the middle (for subsets where $n=40$)
