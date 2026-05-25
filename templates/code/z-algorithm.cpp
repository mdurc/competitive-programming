#include<bits/stdc++.h>
#include "debug.cpp"

std::vector<int> z_function(const std::string& s) {
  int n = (int)s.size();
  std::vector<int> z(n);
  z[0] = 0;
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i > r) {
      if (s[i] != s[0]) { z[i] = 0; continue; }
      l = i, r = i;
      // extend right border
      while (r+1 < n && s[r+1] == s[r-i+1]) ++r;
      z[i] = r - i + 1;
    } else if (i <= r) {
      int k = i - l;
      if (z[k] < r-i+1) {
        z[i] = z[k];
      } else if (z[k] >= r-i+1) {
        l = i;
        // extend right border
        while (r+1 < n && s[r+1] == s[r-i+1]) ++r;
        z[i] = r - i + 1;
      }
    }
  }
  return z;
}

std::vector<int> z_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> z = z_function(pattern + "$" + text);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  for (int i = psz+1; i < psz + tsz + 1; ++i) {
    if (z[i] == psz) res.push_back(i-(psz+1));
  }
  return res;
}

int main() {
  std::string a = "abacaba";
  debug(z_function(a));
}
