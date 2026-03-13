#include <bits/stdc++.h>

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      if (s.size() != t.size()) return false;
      std::map<char,char> mapping;
      std::map<char,bool> is_mapped;
      int n = (int)s.size();
      for (int i = 0; i < n; ++i) {
        if (mapping.find(s[i]) != mapping.end()) {
          s[i] = mapping[s[i]];
          if (s[i] != t[i]) return false;
        } else {
          if (is_mapped[t[i]]) return false;
          mapping[s[i]] = t[i];
          is_mapped[t[i]] = true;
        }
      }
      return true;
    }
};
