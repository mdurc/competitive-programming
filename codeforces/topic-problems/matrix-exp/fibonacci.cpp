#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(_i, _n) for (ll _i = 0; _i < (_n); ++_i)

const int MOD = 1e9 + 7;

struct Matrix {
  int a[2][2] = {{0, 0}, {0, 0}};
  Matrix operator*(const Matrix& other) {
    Matrix res;
    REP(i, 2) REP(j, 2) REP(k, 2) {
      res.a[i][k] = (res.a[i][k] + (ll)a[i][j] * other.a[j][k]) % MOD;
    }
    return res;
  }
};

Matrix bpow(Matrix a, ll b) {
  Matrix res;
  REP(i, 2) res.a[i][i] = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  // [f_n-1 f_n  ]
  // [f_n   f_n+1]

  Matrix m;
  m.a[0][0] = 0;
  m.a[0][1] = 1;
  m.a[1][0] = 1;
  m.a[1][1] = 1;
  cout << bpow(m, n).a[0][1] << "\n";

  return 0;
}
