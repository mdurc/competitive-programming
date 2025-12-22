#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int max_n = 1e5 + 5;
  vector<ll> ps(max_n);
  ps[0] = 0, ps[1] = 1;
  ll l = 0, r = 1;
  for (int i = 2; i < max_n; ++i) {
    ll c = (l + r) % MOD;
    l = r;
    r = c;
    ps[i] = (ps[i - 1] + c) % MOD;
  }

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    cout << (ps[r] - (l - 1 >= 0 ? ps[l - 1] : 0) + MOD) % MOD << "\n";
  }

  return 0;
}
