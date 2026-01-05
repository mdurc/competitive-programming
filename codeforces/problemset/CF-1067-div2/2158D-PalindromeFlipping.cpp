#include <bits/stdc++.h>

int state = -1;
std::vector<std::pair<int,int>> match(std::string& s) {
  std::vector<std::pair<int,int>> res;
  int n = (int)s.size();
  // reduce the string to all zeros or all ones
  // If we find 00 or 11 substring, we can just continue to flip it to extend outward
  // Otherwise need to find a palindrome that is < n size, flip it once, then start from the 00/11 that is created on its border
  int two = -1;
  for (int i = 0; i+1 < n; ++i) {
    if (s[i] == s[i+1]) {
      two = i;
      break;
    }
  }
  if (two == -1) {
    // search for palindrome 1..1
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (l == -1) {
          l = i;
        } else {
          r = i;
          break;
        }
      }
    }
    res.emplace_back(l, r); // flip the palindrome
    for (int i = l; i <= r; ++i) {
      s[i] = s[i]=='0'?'1':'0';
    }
    if (l-1 >= 0) {
      two = l-1;
    } else if (r+1 < n) {
      two = r;
    } else {
      // even after flipping, there are no matching adjacent bits
      std::cout << "-1\n";
      return {};
    }
  }
  // extend outward from the matching two bits
  bool z = s[two] == '0';
  int l = two-1, r = two + 2;
  while (l >= 0 || r < n) {
    while (l >= 0 && (z ? s[l] == '0' : s[l] == '1')) --l;
    while (r < n && (z ? s[r] == '0' : s[r] == '1')) ++r;
    z = !z;
    res.emplace_back(l+1, r-1);
    if (l >= 0) --l;
    if (r < n) ++r;
  }
  // forward and reverse directions of this function should both
  // yield the same final "all_bits"
  if ((z && state == 1) || (!z && state == 0)) {
    res.emplace_back(0, n-1);
    z = !z;
  }
  if (state == -1) state = z?0:1;
  return res;
}

void solve() {
  int n;
  std::string s, t;
  std::cin >> n >> s >> t;
  if (s == t) {
    std::cout << "0\n";
    return;
  }
  state = -1;
  std::vector<std::pair<int,int>> f = match(s);
  std::vector<std::pair<int,int>> r = match(t);
  if (f.empty() || r.empty()) return;

  std::reverse(r.begin(), r.end());

  std::cout << f.size() + r.size() << "\n";
  for (auto [a, b]: f) {
    std::cout << a+1 << " " << b+1 << "\n";
  }
  for (auto [a, b]: r) {
    std::cout << a+1 << " " << b+1 << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
