#include <bits/stdc++.h>

using ll = long long;
void solve_v1() {
  int n;
  std::cin >> n;
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::vector<ll> ps(n);
  ps[0] = a[0];
  for (int i = 1; i < n; ++i) ps[i] = ps[i-1] + a[i];
  /* maximum length valid segment */
  ll mx = *std::max_element(a.begin(), a.end());
  std::vector<ll> ops;
  for (int i = 0; i < n; ++i) {
    ll f = ps[i], r = ps[n-1]-ps[n-(n-i)];
    if (r % f == 0 && f >= mx) {
      ops.push_back(f);
    }
  }
  // debug(ops);
  auto get = [&](ll target) -> int {
    int last = -1;
    int res = INT_MIN;
    for (int i = 0; i < n; ++i) {
      ll cur = ps[i]-(last>=0?ps[last]:0);
      if (cur == target) {
        int len = last >= 0 ? i - last: i+1;
        // debug("at {:",last, i, "} =",len, "with sum", cur);
        res = std::max(res, len);
        last = i;
      }
    }
    return last == n-1 ? res: INT_MAX;
  };
  int res = INT_MAX;
  for (ll target: ops) {
    // debug(get(target));
    res = std::min(res, get(target));
  }
  std::cout << res << "\n";
}


const int mxn = 2001;
int n;
int a[mxn];

int get(int start, int sum) {
  if (start == n) return 0;
  int cur = 0;
  for (int i = start; i < n; ++i) {
    cur += a[i];
    if (cur == sum) return std::max(i-start+1,get(i+1, sum));
    if (cur > sum) return n;
  }
  return n;
}

void solve() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int res = n, sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    res = std::min(res, get(0, sum));
  }
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
