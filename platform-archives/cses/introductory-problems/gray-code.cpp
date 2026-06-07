#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> cur = {"0", "1"};
  for (int i = 1; i < n; ++i) {
    int sz = cur.size();
    for (int j = sz-1; j >= 0; --j) {
      cur.push_back("1" + cur[j]);
      cur[j] = "0" + cur[j];
    }
  }
  for (std::string& s: cur) {
    std::cout << s << "\n";
  }
}
