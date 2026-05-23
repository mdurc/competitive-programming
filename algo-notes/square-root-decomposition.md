### 1. Standard Square Root Decomposition (Arrays)

- **Method (or data structure)** that allows us to perform range operations (sum/min/mix), similar to [segment tree](segment-tree.md), in $O(\sqrt{N})$.

- Divide an array of size $N$ into $\approx \sqrt{N}$ contiguous blocks of size $\sqrt{N}$.
    - Number of blocks is $N / \sqrt{N}$
    - You could technically use any block size, however it turns out that $B = \sqrt{N}$ is the optimal size.
    - Since the time complexity of a query (see below) is $O(\frac{N}{B} + B)$, it will always be optimal to make both terms of the runtime be equivalent. This means that $N/B = B$, which is equivalent to $B = \sqrt{N}$.

* We maintain an aggregate value (sum, min, max) for each block.
* **Updates:** $O(1)$ to update the element and its block's aggregate.
* **Queries:** $O(\sqrt{N})$. The range $[l, r]$ fully covers some middle blocks (accessed in $O(1)$ each) and partially covers the boundary blocks (iterated element-by-element, max $\sqrt{N}$ steps).
    * Time: $O(\frac{N}{\sqrt{N}} + \sqrt{N})$

```cpp
int n;
int a[N], b[N]; // b stores block sums
int b_sz;       // block size (usually sqrt(n))
void update(int i, int val) {
  b[i / b_sz] += val - a[i];
  a[i] = val;
}
int query(int l, int r) {
  int sum = 0;
  int c_l = l / b_sz, c_r = r / b_sz;
  if (c_l == c_r) {
    for (int i = l; i <= r; ++i) sum += a[i];
  } else {
    for (int i = l, end = (c_l + 1) * b_sz; i < end; ++i) sum += a[i];
    for (int i = c_l + 1; i < c_r; ++i) sum += b[i];
    for (int i = c_r * b_sz; i <= r; ++i) sum += a[i];
  }
  return sum;
}
```

### 2. Light and Heavy Vertices (Graph Degree Sqrt Trick)

* When processing graph queries, we can bound the worst-case complexity by classifying vertices by their degree.
    * If we know that some vertices will require more computation, we can do preprocessing and rely on bruteforce for "smaller" vertices.
* **Heavy Vertices:** Degree $> \sqrt{V}$ (or $\sqrt{E}$). There can be at most $O(\sqrt{V})$ such vertices in the entire graph.
* **Light Vertices:** Degree $\le \sqrt{V}$. Iterating through their neighbors takes at most $O(\sqrt{V})$ time.
* **Application:** When answering queries like "update node $u$ and query sum of neighbors", heavy nodes update a stored value for themselves, and light nodes push updates directly to their neighbors. Querying a light node takes $O(\sqrt{V})$ to check heavy neighbors, and querying a heavy node is $O(1)$ using its stored value.
    * For every light node: brute force over neighbors.
    * For every heavy node: $O(N)$.

### 3. Mo's Algorithm (Offline Range Queries)

* Standard offline algorithm to process $Q$ queries on an array of size $N$ in $O(N \sqrt{Q})$ time.
* Sort queries primarily by `L / block_size`, and secondarily by `R`.
* Maintains a sliding window `[curr_l, curr_r]` that shifts to match each query. Because of the sorting order, the total distance moved by `L` and `R` across all queries is strictly bounded.

```cpp
const int mxn = 2e5 + 5;
int block_size;
int a[mxn];
long long current_answer = 0;
long long ans[mxn];
struct Query {
  int l, r, id;
  bool operator<(const Query& o) const {
    int b1 = l / block_size, b2 = o.l / block_size;
    if (b1 != b2) return b1 < b2;
    return (b1 & 1) ? (r < o.r) : (r > o.r);
  }
};

inline void add(int idx) { // add to current_answer }
inline void remove(int idx) { // remove from current_answer }

void solve_mos(std::vector<Query>& queries, int n) {
  block_size = std::max(1, (int)(n / std::sqrt(queries.size() + 1))); 
  std::sort(queries.begin(), queries.end());

  int l = 0, r = -1; // initial empty window
  for (const Query& q : queries) {
    while (l > q.l) add(--l);
    while (r < q.r) add(++r);
    while (l < q.l) remove(l++);
    while (r > q.r) remove(r--);
    
    ans[q.id] = current_answer;
  }
}
```

### Resources
* https://www.youtube.com/watch?v=BJhzd_VG61k
* https://cp-algorithms.com/data_structures/sqrt_decomposition.html#mos-algorithm
