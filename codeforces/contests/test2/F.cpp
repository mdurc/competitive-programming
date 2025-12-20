#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n;
map<pair<int,unsigned long>, int> m;
int solve(vector<string>& s, int idx, bitset<4> a) {
  if (idx == n) {
    return a.all() ? 1 : 0;
  }
  const auto& itr = m.find(make_pair(idx, a.to_ulong()));
  if (itr != m.end()) {
    return itr->second;
  }
  int res = 0;
  bool ok = true;
  bitset<4> b = a;
  for (int i = 0; i < s[idx].size(); ++i) {
    if (s[idx][i] == '1' && a[i]) {
      ok = false;
      break;
    }
    if (s[idx][i] == '1') {
      b.set(i);
    }
  }
  if (ok) {
    res = solve(s, idx+1, b);
  }
  res = (res + solve(s, idx+1, a)) % MOD;
  m[make_pair(idx,a.to_ulong())] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  vector<string> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  cout << solve(p, 0, 0) << "\n";
}
