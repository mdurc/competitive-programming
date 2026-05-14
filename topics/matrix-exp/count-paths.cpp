#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < n; ++i)

int n;
const int MOD = 1e9 + 7;

struct Matrix {
  vector<vector<int>> m;
  int n;
  Matrix(int _n) : n(_n) { m = vector<vector<int>>(_n, vector<int>(_n, 0)); }
  Matrix operator*(const Matrix& b) {
    Matrix res(n);
    REP(i, n) REP(j, n) REP(k, n) {
      res.m[i][k] = (res.m[i][k] + (ll)m[i][j] * b.m[j][k]) % MOD;
    }
    return res;
  }
};

Matrix bpow(Matrix a, int b) {
  Matrix res(a.n);
  REP(i, n) res.m[i][i] = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int m, k;
  cin >> n >> m >> k;

  Matrix adj(n);
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    adj.m[a - 1][b - 1] = 1;
  }

  int ans = 0;
  Matrix res = bpow(adj, k);
  REP(i, n) REP(j, n) { ans = (ans + res.m[i][j]) % MOD; }
  cout << ans << "\n";

  return 0;
}
