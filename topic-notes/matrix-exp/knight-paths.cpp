#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint; // will automatically perform mod 2^32 upon overflow

#define REP(i, n) for(uint i = 0; i < (n); ++i)

const int A = 65;
vector<pair<int, int>> dirs{{-2, -1}, {-2, 1}, {-1, 2}, {-1, -2},
                            {1, 2},   {1, -2}, {2, -1}, {2, 1}};

struct Matrix {
  vector<vector<uint>> a = vector<vector<uint>>(A, vector<uint>(A));
  Matrix operator*(const Matrix& other) {
    Matrix res;
    REP(i, A) REP(j, A) REP(k, A) { res.a[i][k] += a[i][j] * other.a[j][k]; }
    return res;
  }
};
Matrix bpow(Matrix a, int b) {
  Matrix res;
  REP(i, A) res.a[i][i] = 1; // identity
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  int k;
  cin >> k;

  Matrix mat;
  REP(r, 8) {
    REP(c, 8) {
      for (auto [dr, dc] : dirs) {
        int nr = r + dr;
        int nc = c + dc;
        if (0 <= min(nr, nc) && max(nr, nc) < 8) {
          mat.a[r * 8 + c][nr * 8 + nc] = 1;
        }
      }
    }
  }
  REP(i, 65) mat.a[i][64] = 1;
  cout << bpow(mat, k + 1).a[0][64] << "\n";
}
