#include <bits/stdc++.h>

std::string conv(std::map<char,char>& m, std::string& a) {
  std::string res = "";
  for (char c: a) {
    res += m[c];
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::map<char,char> m;
  std::vector<std::string> strs = {"oqz","ij","abc","def","gh","kl","mn","prs","tuv","wxy"};
  for (int i = 0; i < (int)strs.size(); ++i) {
    for (char c: strs[i]) {
      m[c] = '0'+i;
    }
  }

  std::string s;
  while (std::cin >> s) {
    if (s == "-1") break;
    int n = (int)s.size();
    int os;
    std::cin >> os;
    std::vector<std::pair<std::string,std::string>> ops(os);
    for (int i = 0; i < os; ++i) {
      std::cin >> ops[i].first;
      ops[i].second = conv(m,ops[i].first);
    }

    std::vector<int> dp(n+1, 1e9);
    std::vector<int> path(n+1,-1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < os; ++j) {
        int sz = (int)ops[j].first.size();
        if (i - sz >= 0 && s.substr(i-sz,sz)==ops[j].second && dp[i-sz]+1 < dp[i]) {
          dp[i] = dp[i-sz]+1;
          path[i] = j;
        }
      }
    }
    if (dp[n] == 1e9) {
      std::cout << "No solution.\n";
    } else {
      std::vector<int> res(dp[n]);
      int pos = n;
      for (int i = dp[n]-1; i >= 0; --i) {
        res[i] = path[pos];
        pos -= ops[res[i]].first.size();
      }
      for (int i: res) {
        std::cout << ops[i].first << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}

