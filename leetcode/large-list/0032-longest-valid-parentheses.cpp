#include <bits/stdc++.h>

class Solution {
  public:
    int longestValidParentheses(string s) {
      int n = (int)s.size();
      std::vector<int> dp(n+1, 0); /* len ending at i */
      std::stack<int> opened;
      int res = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
          if (!opened.empty()) {
            int pos = opened.top(); opened.pop();
            dp[i] = i-pos+1 + (pos > 0 ? dp[pos-1]:0);
            res = std::max(res, dp[i]);
          }
        } else {
          opened.push(i);
        }
      }
      return res;
    }
};
