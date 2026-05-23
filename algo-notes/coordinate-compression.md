## Coordinate Compression

> **TL;DR:** Maps a sparse set of large values (up to $10^9$) into a dense, continuous range of small integers ($0 \dots M-1$, where $M \le N$). This is strictly necessary when you need to use array values as indices for a frequency array, [Fenwick Tree](fenwick-tree.md), or [Segment Tree](segment-tree.md), but the values exceed memory limits.

* **Main Idea:** The absolute values of the elements often do not matter; only their **relative order** (ranks) matters. 
* By sorting all unique values in the dataset, we can assign an index $0, 1, 2, \dots$ to each distinct value. 
* This reduces the range of values from $O(\max(A))$ down to $O(N)$, allowing arrays of size $N$ to be used for state tracking.

* **Implementation:**
    1. Collect all values that need to be compressed into an auxiliary vector.
    2. Sort the vector and remove duplicates using `std::sort` and `std::unique`.
    3. To find the compressed value (rank) of any original number, use `std::lower_bound` to find its index in the unique vector.

```cpp
const int mxn = 2e5 + 5;
int n;
long long a[mxn];
int compressed[mxn];

void compress() {
  std::vector<long long> vals;
  for (int i = 0; i < n; i++) vals.push_back(a[i]);

  std::sort(vals.begin(), vals.end());
  vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

  for (int i = 0; i < n; i++) {
    // note that for fenwick trees this must be +1 for 1-based indexing
    compressed[i] = std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
  }
}
