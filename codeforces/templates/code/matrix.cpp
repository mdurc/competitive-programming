const int N = 2; // 2x2 matrix
const int MOD = 1e9;
struct matrix_t {
  int x[N + 1][N + 1]; // 1-based matrix!
  // zero matrix by default, or identity if v=1
  matrix_t(int v = 0) {
    memset(x, 0, sizeof(x));
    if (v != 0) {
      for (int i = 1; i <= N; ++i) x[i][i] = v % MOD;
    }
  }
  matrix_t operator*(const matrix_t& r) const {
    matrix_t p;
    for (int k = 1; k <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
        if (x[i][k] == 0) continue;
        for (int j = 1; j <= N; ++j) {
          p.x[i][j] = (p.x[i][j] + 1LL * x[i][k] * r.x[k][j]) % MOD;
        }
      }
    }
    return p;
  }
  matrix_t power(ll p) const {
    matrix_t r(1);
    matrix_t a = *this;
    while (p) {
      if (p & 1) r = r * a;
      a = a * a;
      p >>= 1;
    }
    return r;
  }
  // mod must be prime for fermat's little theorem
  static int mod_inv(int a) {
    int res = 1, b = a, e = MOD - 2;
    while (e) {
      if (e & 1) res = 1LL * res * b % MOD;
      b = 1LL * b * b % MOD;
      e >>= 1;
    }
    return res;
  }

  matrix_t inverse() const {
    matrix_t a = *this;
    matrix_t inv(1);

    for (int i = 1; i <= N; ++i) {
      int pivot = -1;
      for (int j = i; j <= N; ++j) {
        if (a.x[j][i] != 0) {
          pivot = j;
          break;
        }
      }
      if (pivot == -1) throw runtime_error("Matrix is singular");
      if (pivot != i) {
        swap(a.x[i], a.x[pivot]);
        swap(inv.x[i], inv.x[pivot]);
      }
      int inv_pivot = mod_inv(a.x[i][i]);
      for (int j = 1; j <= N; ++j) {
        a.x[i][j] = 1LL * a.x[i][j] * inv_pivot % MOD;
        inv.x[i][j] = 1LL * inv.x[i][j] * inv_pivot % MOD;
      }
      for (int j = 1; j <= N; ++j) {
        if (i == j) continue;
        int factor = a.x[j][i];
        for (int k = 1; k <= N; ++k) {
          a.x[j][k] = (a.x[j][k] - 1LL * factor * a.x[i][k] % MOD + MOD) % MOD;
          inv.x[j][k] =
              (inv.x[j][k] - 1LL * factor * inv.x[i][k] % MOD + MOD) % MOD;
        }
      }
    }
    return inv;
  }
};

// simple 2x2 matrix multiplication
void mul(ll a[2][2], ll b[2][2]) {
  ll res[2][2];
  res[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
  res[0][1] = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
  res[1][0] = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
  res[1][1] = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
  memcpy(a, res, sizeof(res));
}

int main() {
  int n = 10;
  matrix_t fib; // transformation matrix
  fib.x[1][1] = 1;
  fib.x[1][2] = 1;
  fib.x[2][1] = 1;
  fib.x[2][2] = 0;

  // Claim to our induction over the transformation matrix
  // [0 1]^n [f(0)] = [ f(n) ]
  // [1 1]   [f(1)] = [f(n+1)]
  matrix_t result = fib.power(n);
  cout << "fib(" << n << ") = " << (result.x[1][1] * 0 + result.x[1][2] * 1) % MOD << endl;

  // alternative simpler approach:
  ll mat[2][2] = {{0, 1}, {1, 1}};
  ll res[2][2] = {{1, 0}, {0, 1}}; // identity matrix
  // calculate mod-pow
  while (n) {
    if (n & 1) mul(res, mat);
    mul(mat, mat);
    n >>= 1;
  }
  // mult by [f(0), f(1)] vector and get f(n)
  cout << (res[0][0] * 0 + res[0][1] * 1) << "\n";
}
