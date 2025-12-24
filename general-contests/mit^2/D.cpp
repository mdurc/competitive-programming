#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> divisors(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  // sort(res.begin(), res.end());
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<int> opts = divisors(a[0]);
    int ans = -1;
    for (int x : opts) {
      bool div = false, mul = false, ok = true;
      for (ll i : a) {
        if (i % x == 0) div = true;
        if (x % i == 0) mul = true;
        if (x % i != 0 && i % x != 0) {
          ok = false;
          break;
        }
      }
      if (ok && div && mul) {
        ans = x;
        break;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
