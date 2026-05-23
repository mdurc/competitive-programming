## Bit Manipulation

> **TL;DR:** Leverage integer binary representations to efficiently represent subsets, optimize space, and perform operations in $O(1)$ time. Essential for subsets, [bitmask DP](bitmask-dp.md), and [combinatorial](combinatorics.md) brute-force.

### Fundamentals

- **Binary is base 2:** $13_{(10)} = 2^3 + 2^2 + 2^0 = 1101_{(2)} = 00001101_{(2)}$
  - **Most siginifcant bit** is the leftmost set-bit, as it contributes the largest value.
  - **Least significant bit** is the rightmost set-bit, as it contributes the least.
  - In C++, `0` denotes false and `1` denotes true when used in conditional statments.

- **Types:**
  - `char` is 8 bits (1 byte)
  - `short` is 16 bits (2 bytes)
  - `int` is 32 bits (4 bytes)
  - `long` and `long long` are 64 bits (8 bytes)
  - `float` is 32 bits (4 bytes)
  - `double` is 64 bits (8 bytes)

### Bitwise AND, OR, XOR

| A | B | A AND B | A OR B | A XOR B |
| - | - | ------- | ------ | ------- |
| 0 | 0 | 0       | 0      | 0       |
| 0 | 1 | 0       | 1      | 1       |
| 1 | 0 | 0       | 1      | 1       |
| 1 | 1 | 1       | 1      | 0       |

* **AND (`&`)**: `1` only if both bits are `1`
* **OR (`|`)**: `1` if either bit is `1`
* **XOR (`^`, $\oplus$)**: `1` if the bits are different (`A != B`)

```
  110101   (53)
& 011100   (28)
--------
  010100   (20)
```

### Bitwise Shifts
- `<<` shifts bits to the left, multiplying the value by 2.
- `>>` shifts bits to the right, dividing the value by 2.
```
    LEFT SHIFT                             RIGHT SHIFT
       13 =     1101                          13 =   1101
(13 << 2) =   110100                   (13 >> 2) =     11   
```
- Since we shifted `13` by 2, we multiplied/divided it by $2^2 = 4$ instead of $2^1 = 2$.
- `x << b` is equal to $x \cdot 2^b$.
- `x >> b` is equal to $\lfloor \frac{x}{2^b} \rfloor$, note this is the floor due to integer division.

* **Warning on Shift Overflow:** `1 << x` operates on a 32-bit signed integer. If you are shifting 31 or more bits, you must use `1LL << x` to operate on a 64-bit integer.

### Common Operations and Properties
* **Check $i$-th bit:** `(mask >> i) & 1` (returns 1 if set, 0 otherwise)
* **Set $i$-th bit:** `mask | (1 << i)`
* **Clear $i$-th bit:** `mask & ~(1 << i)`
* **Toggle $i$-th bit:** `mask ^ (1 << i)`
* **Check for even/odd:** `mask & 1` is true for odd numbers.
* **Multiply/Divide by 2:** `mask << 1` (multiply) and `mask >> 1` (divide)
* **Get Lowest Set Bit (LSB):** `mask & -mask`. extracts the least significant bit (rightmost-set-bit). It is the foundational mechanism for [Fenwick Trees](fenwick-tree.md).


### XOR Tricks

* The XOR operator (`^`) acts as addition without carry (addition modulo 2).
    * See [game theory notes](game-theory.md) for a particular use-case in Nim game.

- **Properties:**
    - **Self-Inverse:** $x \oplus x = 0$. Every number is its own negative.
    - **Identity:** $x \oplus 0 = x$.
    - **Range XOR Queries:** Because XOR is its own inverse, you can compute range XORs on a static array in $O(1)$ time using a prefix XOR array.
    - `prefix[r] ^ prefix[l-1]` yields the XOR sum of the subarray $[l, r]$.

### GCC Built-in Functions

* Use the `ll` suffix (`__builtin_popcountll`) when working with 64-bit `long long` integers.

* `__builtin_popcount(x)`: number of set bits (1s) in $x$.
* `__builtin_ctz(x)`: number of trailing zeros. *(0-based index of the lowest set bit)*
* `__builtin_clz(x)`: number of leading zeros. *(`31 - __builtin_clz(x)` yields the MSB)*

### Bitsets
- `std::bitset<N>` can be used as a fixed-size boolean array.
- **Advantages:** very fast bulk-operations and very low memory footprint (1-bit per element instead of 1-byte per element in a `bool[N]` array).
```cpp
const int mxn = 1000;
std::bitset<mxn> b; // initialized to all 0s

// O(1) operations
b.set(5);   // set bit 5 to 1
b.reset(5); // set bit 5 to 0
b.flip(5);  // toggle bit 5
b[5] = 1;   // subscript access

// O(N/64) operations
b.set();    // set ALL bits to 1
b.reset();  // set ALL bits to 0
b.flip();   // toggle ALL bits
b <<= 3;    // shift all bits left by 3

// Queries
int cnt = b.count();      // number of set bits (popcount)
bool has_any = b.any();   // true if any bit is set
bool has_none = b.none(); // true if no bits are set
```

### Subset Traversal
* A subset of items $0, 1, \dots, N-1$ is often represented as a single integer (a **bitmask**) where the $i$-th bit is `1` if item $i$ is in the subset, and `0` otherwise.
- **Iterate over all subsets of size $N$:**
```cpp
int n = 5;
for (int mask = 0; mask < (1 << n); ++mask) {
  for (int i = 0; i < n; ++i) {
    if (mask & (1 << i)) {
      // element i is included in the subset
    }
  }
}
```

### Hamming Weight
- A common question is to find the `popcount`, or `hamming weight`, which is the number of set bits in a number.
- The naive approach is $O(\log N)$ in the number of total bits in the integer (32 or 64)
```cpp
int count = 0;
while (n > 0) {
  count += (n & 1);
  n >>= 1;
}
```
- The optimized approach is $O(\log N)$ in the number of total **set bits**.
```cpp
int count = 0;
while (n > 0) {
  n &= (n - 1); // clears the LSB
  // n ^= (n & -n); // clears the LSB (alternative)
  count++;
}
```

### Resources
* https://cp-algorithms.com/algebra/bit-manipulation.html
* https://codeforces.com/blog/entry/73490
    * https://www.youtube.com/watch?v=xXKL9YBWgCY
