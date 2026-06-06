#include <bits/stdc++.h>

int main() {
  std::string s;
  std::cin >> s;

  int n = s.size();
  int cnt[26] = {}, odds = 0;
  // std::fill(cnt, cnt+26, 0);
  for (int i = 0; i < n; ++i) cnt[s[i]-'A']++;
  for (int i = 0; i < 26; ++i) odds += cnt[i]&1;

  if (odds > 1) {
    std::cout << "NO SOLUTION\n";
    return 0;
  }

  int l = 0, odd_pos = -1;
  std::string res(n, ' ');
  for (int i = 0; i < n; ++i) {
    int c = cnt[s[i]-'A'];
    if (c&1) {
      odd_pos = i;
      continue;
    }
    cnt[s[i]-'A'] = 0;
    for (int j = l; l-j < c/2; ++l) {
      res[l] = s[i];
      res[n-l-1] = s[i];
    }
  }
  if (odd_pos != -1) {
    while (l < n && res[l] == ' ') {
      res[l++] = s[odd_pos];
    }
  }
  std::cout << res << "\n";
}
