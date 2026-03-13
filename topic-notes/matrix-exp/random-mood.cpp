#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

struct Matrix {
  double a[2][2] = {{0, 0}, {0, 0}};
  Matrix operator*(const Matrix& other) {
    Matrix res;
    REP(i, 2) REP(j, 2) REP(k, 2) { res.a[i][k] += a[i][j] * other.a[j][k]; }
    return res;
  }
};
Matrix bpow(Matrix a, int b) {
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

  int n;
  double p;
  cin >> n >> p;
  // vector<double> dp = {0.0, 1.0};
  // for (int i = 1; i <= n; ++i) {
  //   double h = dp[0] * p + dp[1] * (1 - p);
  //   double s = dp[0] * (1 - p) + dp[1] * p;
  //   dp = {s, h};
  // }
  // cout << fixed << setprecision(10) << dp[1] << "\n";

  Matrix m;
  m.a[0][0] = 1 - p;
  m.a[0][1] = p;
  m.a[1][0] = p;
  m.a[1][1] = 1 - p;
  cout << setprecision(10) << fixed << bpow(m, n).a[0][0] << endl;

  return 0;
}
