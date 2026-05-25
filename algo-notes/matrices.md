## Matrices

- More frequently used for calculating state transitions in linear recurrences.
    - Not often used for 3D graphics, rotation matrices, etc.

- The time complexity of matrix multiplication is $O(N^3)$, which is very slow.
- We can use the loop order: `i, k, j` to improve via cache locality, but this is still a slow operation.
```cpp
const int MOD = 1e9 + 7;
struct Matrix {
  int n;
  vector<vector<long long>> a;
  Matrix(int n) : n(n), a(n, vector<long long>(n, 0)) {}
  Matrix operator*(const Matrix& other) const {
    Matrix res(n);
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
          res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
        }
      }
    }
    return res;
  }
};
```

### Matrix Exponentiation
- Just as we used [binary exponentiation](modular-arithmetic.md) to calculate $a^b$ in $O(\log b)$ time, we can apply the exact same logic to compute $A^b$ where $A$ is a matrix.
    - This allows us to multiply a matrix by itself $10^{18}$ times in roughly 60 operations.
```cpp
Matrix binpow(Matrix base, long long exp) {
  Matrix res(base.n);
  // Initialize to identity matrix
  for (int i = 0; i < base.n; i++) res.a[i][i] = 1; 
  while (exp > 0) {
    if (exp & 1) res = res * base;
    base = base * base;
    exp >>= 1;
  }
  return res;
}
```

### Linear Recurrences

- This is the most common application of matrices.
- If a DP state or mathematical sequence relies solely on a linear combination of previous terms, we can find the $N$-th term in $O(K^3 \log N)$ time (where $K$ is the number of previous terms it depends on).
- **Intuition:** We define a **State Vector** (a $K \times 1$ matrix) holding our current values, and a **Transition Matrix** (a $K \times K$ matrix) that dictates how to move to the next state.

> **Example: Fibonacci Sequence**
- The Fibonacci sequence is defined as $F_n = F_{n-1} + F_{n-2}$. It depends on $K=2$ previous terms.
- We want to find a matrix $T$ such that:

$$T \times \begin{pmatrix} F_{n-1} \\ F_{n-2} \end{pmatrix} = \begin{pmatrix} F_{n} \\ F_{n-1} \end{pmatrix}$$

- By solving the system of equations, the transition matrix $T$ is:

$$\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \times \begin{pmatrix} F_{n-1} \\ F_{n-2} \end{pmatrix} = \begin{pmatrix} 1 \cdot F_{n-1} + 1 \cdot F_{n-2} \\ 1 \cdot F_{n-1} + 0 \cdot F_{n-2} \end{pmatrix} = \begin{pmatrix} F_{n} \\ F_{n-1} \end{pmatrix}$$

- To find the $N$-th Fibonacci number, we simply raise $T$ to the power of $N-1$ and multiply it by our base cases.

$$\begin{pmatrix} F_N \\ F_{N-1} \end{pmatrix} = T^{N-1} \times \begin{pmatrix} F_1 \\ F_0 \end{pmatrix}$$

### Graphs and Matrices
- Graphs and matrices share a strict mathematical equivalence.
    - An unweighted directed graph can be represented as an adjacency matrix $A$, where $A[u][v] = 1$ if there is an edge from $u$ to $v$, and $0$ otherwise.

- If you take an adjacency matrix $A$ and raise it to the $k$-th power, the value at $A^k[u][v]$ will be exactly the **number of distinct paths of length $k$** from node $u$ to node $v$.
    - If a problem asks "How many ways can you travel from city $X$ to city $Y$ in exactly $10^9$ steps?", we can construct the adjacency matrix and use Matrix Exponentiation to compute $A^{10^9}$.
