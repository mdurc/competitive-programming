// Calculate sum(i=l to r) fib_i
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void mul(ll a[2][2], ll b[2][2]) {
  ll res[2][2];
  res[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
  res[0][1] = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
  res[1][0] = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
  res[1][1] = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
  memcpy(a, res, sizeof(res));
}

int get(int n) {
  ll mat[2][2] = {{0, 1}, {1, 1}};
  ll res[2][2] = {{1, 0}, {0, 1}};
  while (n) {
    if (n & 1) mul(res, mat);
    mul(mat, mat);
    n >>= 1;
  }
  return res[0][1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ((get(r+2) - get(l+1))+MOD)%MOD << "\n";
  }

  return 0;
}
