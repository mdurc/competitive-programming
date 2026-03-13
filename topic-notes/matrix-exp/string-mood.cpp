#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(_i, _n) for (ll _i = 0; _i < (_n); ++_i)

const int MOD = 1e9 + 7;

struct Matrix {
  vector<vector<int>> mat;
  Matrix() : mat(2, vector<int>(2, 0)) {}
  Matrix operator*(const Matrix& other) {
    Matrix res;
    REP(i, 2) REP(j, 2) REP(k, 2) {
      res.mat[i][k] = (res.mat[i][k] + (ll)mat[i][j] * other.mat[j][k]) % MOD;
    }
    return res;
  }
};

Matrix bpow(Matrix a, ll b) {
  Matrix res;
  REP(i, 2) res.mat[i][i] = 1;
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

  Matrix m;
  m.mat = {{19, 6}, {7, 20}};
  cout << bpow(m, n).mat[0][0] << "\n";

  // vector<ll> dp = {7, 19};
  // for (int i = 2; i <= n; ++i) {
  //   ll new_sad = ((dp[0] * 20) % MOD + (dp[1] * 7) % MOD) % MOD;
  //   ll new_happy = ((dp[0] * 6) % MOD + (dp[1] * 19) % MOD) % MOD;
  //   dp = {new_sad, new_happy};
  // }

  return 0;
}
