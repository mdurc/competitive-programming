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
// return indices of text that start a substring that matches pattern
std::vector<int> z_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> z = z_function(pattern + "$" + text);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  for (int i = psz+1; i < psz + tsz + 1; ++i) {
    if (z[i] == psz) res.push_back(i-(psz+1));
  }
  return res;
}

std::vector<int> prefix_function(const std::string& s) {
  int n = (int)s.size();
  std::vector<int> lps(n);
  lps[0] = 0;
  int l = 0, r = 1;
  while (r < n) {
    if (s[l] == s[r]) {
      lps[r] = l+1;
      ++l, ++r;
    } else {
      if (l == 0) ++r;
      else l = lps[l-1];
    }
  }
  return lps;
}

// version 1: concatenation
std::vector<int> prefix_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> pi = prefix_function(pattern + "$" + text);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  for (int i = psz+1; i < psz + tsz + 1; ++i) {
    // 0-based starting index in text (i - (psz-1) - (psz+1))
    if (pi[i] == psz) res.push_back(i - 2 * psz);
  }
  return res;
}

// version 2: kmp state machine
std::vector<int> kmp_patterns(const std::string& pattern, const std::string& text) {
  std::vector<int> res;
  std::vector<int> lps = prefix_function(pattern);
  int psz = (int)pattern.size(), tsz = (int)text.size();
  // LPS construction algorithm but with pattern[l], text[r]
  int l = 0, r = 0;
  while (r < tsz) {
    if (pattern[l] == text[r]) {
      ++l;
      ++r;
      if (l == psz) {
        res.push_back(r-l);
        // we reached full full prefix length, go back to the last prefix-suffix to keep searching
        l = lps[l-1];
      }
    } else {
      if (l == 0) ++r;
      else l = lps[l-1];
    }
  }
  return res;
}

int main() {
  std::string a = "abacaba";
  debug(z_function(a));

  std::string b = "ababcabab";
  debug(prefix_function(b));
}
