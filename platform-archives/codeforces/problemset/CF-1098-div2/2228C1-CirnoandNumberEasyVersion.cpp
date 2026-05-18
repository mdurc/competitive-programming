#include <bits/stdc++.h>

using u64 = unsigned long long;

void solve() {
  u64 a;
  int n;
  std::cin >> a >> n;
  std::vector<int> d(n);
  for (int i = 0; i < n; ++i) std::cin >> d[i];
  std::string a_str = std::to_string(a);
  int len = (int)a_str.size();

  u64 mdiff = 1e18;
  auto check = [&](const std::string& s) {
    if (s.empty()) return;
    u64 val = 0;
    for (char c: s) val = val*10 + (c-'0');
    mdiff = std::min(mdiff, a>val ? a-val: val-a);
  };

  // less
  if (len > 1) check(std::string(len - 1, d.back() + '0'));

  // larger
  auto itr = std::upper_bound(d.begin(), d.end(), 0);
  if (itr != d.end()) {
    std::string cand = "";
    cand += (*itr + '0');
    cand += std::string(len, d[0] + '0');
    check(cand);
  } else {
    check("0");
  }

  // equal
  std::string p = "";
  for (int i = 0; i <= len; ++i) {
    if (i == len) {
      check(p);
      break;
    }
    int c = a_str[i] - '0';
    itr = std::lower_bound(d.begin(), d.end(), c);
    if (itr != d.begin()) {
      std::string cand = p;
      cand += (*(--itr) + '0');
      cand += std::string(len-i-1, d.back() + '0');
      check(cand);
    }
    itr = std::upper_bound(d.begin(), d.end(), c);
    if (itr != d.end()) {
      std::string cand = p;
      cand += (*itr + '0');
      cand += std::string(len-i-1, d[0] + '0');
      check(cand);
    }
    if (!std::binary_search(d.begin(), d.end(), c)) break;
    p += a_str[i];
  }

  std::cout << mdiff << "\n";
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
