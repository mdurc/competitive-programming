#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  int cnt[26] = {0};
  char last = '.';
  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (last != s[i]) {
      last = s[i];
      len = 0;
    }
    if (++len == k) {
      cnt[s[i]-'a']++;
      len = 0;
    }
  }
  std::cout << *std::max_element(cnt,cnt+26) << "\n";

  return 0;
}
