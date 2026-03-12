#include <bits/stdc++.h>

class Solution {
  public:
    int myAtoi(std::string s) {
      int n = s.size();
      int i = 0;
      while (i < n && std::isspace(s[i])) ++i;

      if (i >= n) return 0;

      bool neg = 0;
      if (s[i] == '+' || s[i] == '-') {
        neg = (s[i] == '-');
        ++i;
      }

      long long res = 0;
      while (i < n && std::isdigit(s[i])) {
        res = res*10 + (s[i] - '0');
        if (res > INT_MAX) {
          return neg ? INT_MIN : INT_MAX;
        }
        ++i;
      }
      return neg ? -res : res;
    }
};
