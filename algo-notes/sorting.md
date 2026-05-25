> **TL;DR:** Comparison based sorting algorithms can run in $O(N \log N)$ worst case.
> There are some algorithms like Quicksort that can achieve a best-case $O(N)$, and Radix-Sort that achieves $O(nk)$ worst case on integers/strings, but these are not reliable and "general-purpose".

## Merge Sort

- Merge Sort is a "general-purpose" **divide-and-conquer** comparison sorting algorithm that runs in $O(N \log N)$ time.
    * Continuously split the array in half until it reaches single elements (which are inherently sorted).
    * Repeatedly merges these smaller sorted arrays back together into larger sorted arrays until the entire dataset is reassembled.

1. **Divide:** Find the midpoint of the array and recursively split it into a left half and a right half.
2. **Conquer:** Once the subarrays are divided down to single elements, begin merging them.
3. **Merge:** Compare the elements at the front of the left and right subarrays, pulling the smaller element into a new temporary array. 

* **Time Complexity:** $O(N \log N)$ in the best, worst, and average cases. The array is divided $\log N$ times, and the merge step takes $O(N)$ time at each level.
* **Space Complexity:** $O(N)$. It requires temporary arrays to hold the data during the merging process. 
* **Stability:** Merge Sort is **stable** (identical values maintain their relative order). When merging, if two elements are equal, you simply pull from the left subarray first.

```cpp
int n;
int a[mxn], tmp[mxn];
void merge(int low, int mid, int high) {
  int lval = low, hval = mid+1, index = low;
  while (lval <= mid && hval <= high) {
    if (a[lval] <= a[hval]) {
      tmp[index] = a[lval];
      ++lval;
    } else {
      tmp[index] = a[hval];
      ++hval;
    }
    ++index;
  }
  for (; lval <= mid; ++lval, ++index) tmp[index] = a[lval];
  for (; hval <= high; ++hval, ++index) tmp[index] = a[hval];
  for (int i = low; i <= high; ++i) a[i] = tmp[i];
}

void mergesort(int low, int high) {
  if (low >= high) return;
  int mid = low+(high-low)/2;
  mergesort(low, mid);
  mergesort(mid+1, high);
  merge(low, mid, high);
}
```

## Selection Sort

- Selection Sort is one of the most basic comparison-based sorting algorithms. 
- It is very inefficient ($O(N^2)$), however the implementation is very straightforward.

The algorithm divides the array into two parts: the sorted part at the beginning, and the unsorted part at the end. 
1. **Search:** Iterate through the unsorted portion of the array to find the absolute smallest element.
2. **Swap:** Swap that smallest element with the first unsorted element.
3. **Advance:** Move the boundary between the sorted and unsorted parts one element to the right, and repeat.

```cpp
int n;
int a[mxn];
for (int i = 0; i < n-1; ++i) {
  int mn = i;
  for (int j = i+1; j < n; ++j) {
    if (a[j] < a[mn]) {
      mn = j;
    }
  }
  std::swap(a[i], a[mn]);
}
```

## Counting Sort

- Counting Sort is a **non-comparison algorithm** that works by counting the number of objects that possess distinct key values, then calculating the exact position of each object in the output sequence.

**To achieve stability, we must perform the following version of this algorithm:**
1. **Count:** Tally the frequencies of each element in a `count` array.
    - *Note: Because array indices cannot be negative, this implementation only handles **non-negative integers**.*
2. **Prefix Sums:** Convert the frequencies into *1-based ending indices* (if there are three `0`s, the bucket for `1` starts at index 3).
3. **Place:** Iterate through the original data and place each item into its designated bucket.

* **Time Complexity:** $O(N + K)$, where $N$ is the number of elements and $K$ is the maximum value in the array. 
* **Space Complexity:** $O(N + K)$. 
* **The Catch:** Counting sort requires the maximum value ($K$) to be relatively small. If you are sorting an array of 5 items, but the maximum element is very large, the `count` array will run out of memory.

> **Enforcing Stability:** It is necessary to iterate backwards when placing the values into the output array. As an example, imagine we are sorting the following based **solely on the first element of each pair:**
- **Input:** `[(2, "A"), (1, "B"), (2, "C")]`
    - *Notice that `(2, "A")` appears before `(2, "C")` in the original array.*
- After performing the frequency calculations:
    - `cnt[1] = 1`
    - `cnt[2] = 2`
- After performing prefix-sum calculations to obtain starting indices (**1-based**):
    - `cnt[1] = 1`: the first index of the sorted array (`a[0]`) will be `(1, ..)`.
    - `cnt[2] = 3`: the second and third index of the sorted array (`a[1], a[2]`) will be `(2, ..)`.
    - Thus, the final sorted array is reserved to be: `[(1, "B"), (2, ..), (2, ..)]`
- **The prefix-sum calculation starts with the rightmost index for each value we need to insert.** After we place an element, we decrement the `cnt[element_value]` to obtain the next index.
- This order is inserting elements of each bucket from **right-to-left**.
    - When we iterate through `[(2, "A"), (1, "B"), (2, "C")]`, we will place `(2, "A")` at position `cnt[(2, "A")] - 1` (one-based indexing).
    - **But this is wrong!** For this to be stable, we need to preserve the *original order of identical elements*. Since `(2, "A")` and `(2, "C")` have identical keys (`2`), we need to place `(2, "C")` at the rightmost position first.
    - Thus, we must iterate through the original array from right to left.

```cpp
int n;
int a[mxn], tmp[mxn];
int cnt[mxk+1]; // frequency map for element values

void sort() {
  for (int i = 0; i <= mxk; ++i) cnt[i] = 0;             // reset counts
  for (int i = 0; i < n; ++i) cnt[a[i]]++;               // digit frequencies
  for (int i = 1; i <= mxk; ++i) cnt[i] += cnt[i-1];     // prefix sums for positions

  // iterating backwards is necessary for stability
  for (int i = n-1; i >= 0; --i) {
    tmp[--cnt[a[i]]] = a[i];
  }
  for (int i = 0; i < n; ++i) a[i] = tmp[i];
}
```

**If you do not need the sort to be stable, the approach can be simplified:**
1. **Count:** Tally the frequencies of each element in a `count` array.
    - *Note: Because array indices cannot be negative, this implementation only handles **non-negative integers**.*
2. **Overwrite:** Iterate through the `count` array from $0$ up to the maximum value. Whenever a count is greater than zero, write that index directly back into the original array and decrement the count until it hits zero.

```cpp
int n;
int a[mxn];
int cnt[mxk+1]; 

void sort() {
  for (int i = 0; i <= mxk; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) cnt[a[i]]++;

  int cur = 0;
  for (int i = 0; i <= mxk; ++i) {
    while (cnt[i] > 0) {
      a[cur++] = i;
      cnt[i]--;
    }
  }
}
```

## Radix Sort

- Counting Sort only works on single integers within a small range. To sort **multi-part data** (large numbers with many digits, strings, or pairs/tuples), we use **Radix Sort**.
- **Radix Sort** breaks the data down into its component parts (its "radix" or base) and applies a **stable** Counting Sort to each part sequentially.
  - We process data from the least significant part to the most significant part (sorting the 1s place, then the 10s place, then the 100s place).

* **Stability Matters:** The underlying Counting Sort *must* be stable.
    * When sorting by the 10s place, if two numbers have the same 10s digit (like `21` and `25`), a stable sort ensures they stay in the relative order established during the 1s place sort.
* **Example:** Sorting `[25, 12, 21]`
    * *Sort by 1s place:* `[21, 12, 25]`
    * *Sort by 10s place:* `[12, 21, 25]` (Note that `21` correctly stays before `25` because of stability).

* **Time Complexity:** $O(d \cdot (N + K))$, where $d$ is the number of parts/digits, $N$ is the number of elements, and $K$ is the radix (10 for decimal digits).
    * If $d$ is a small constant, this simplifies to $O(N)$.

```cpp
int n;
int a[mxn], tmp[mxn];
int cnt[10]; // base-10 digits

void radixsort() {
  int mx = *std::max_element(a, a+n);

  // Run counting sort for every digit place
  for (long long exp = 1; mx / exp > 0; exp *= 10) {
    for (int i = 0; i < 10; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) cnt[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; ++i) cnt[i] += cnt[i - 1];
    
    for (int i = n - 1; i >= 0; --i) {
      int digit = (a[i] / exp) % 10;
      tmp[--cnt[digit]] = a[i];
    }
    
    for (int i = 0; i < n; ++i) a[i] = tmp[i];
  }
}
```

### Radix-Sort on Pairs

We can represent a pair `(left, right)` as a 2-digit number.
* The `left` element is the **10s place** (Most Significant).
* The `right` element is the **1s place** (Least Significant).

Instead of looping through powers of 10 (`exp = 1, 10, 100`), Radix Sort on pairs is exactly **two passes** of the stable counting sort.
1. **Pass 1 (Least Significant):** Sort the pairs strictly by their `right` value.
2. **Pass 2 (Most Significant):** Sort the pairs strictly by their `left` value.

> **Note:** this implementation uses `mxk` to denote the limit on the maximum element we can track in our frequency array. In some use-cases of this algorithm ([suffix-array](suffix-array.md)) we can assume that `mxk = mxn`.

```cpp
int n;
std::pair<int, int> a[mxn], tmp[mxn];
int cnt[mxk+1];

void radixsort() {
  // counting sort on right element
  for (int i = 0; i <= mxk; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) cnt[a[i].second]++;
  for (int i = 1; i <= mxk; ++i) cnt[i] += cnt[i - 1];
  for (int i = n - 1; i >= 0; --i) {
    tmp[--cnt[a[i].second]] = a[i];
  }
  for (int i = 0; i < n; ++i) a[i] = tmp[i];

  // counting sort on left element
  for (int i = 0; i <= mxk; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) cnt[a[i].first]++;
  for (int i = 1; i <= mxk; ++i) cnt[i] += cnt[i - 1];
  for (int i = n - 1; i >= 0; --i) {
    tmp[--cnt[a[i].first]] = a[i];
  }
  for (int i = 0; i < n; ++i) a[i] = tmp[i];
}
```
