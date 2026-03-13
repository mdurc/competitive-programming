#include <bits/stdc++.h>

void solve1() {
  std::string s;
  std::cin >> s;

  int n = s.size(), last = -1, as = 0;
  std::string a = "";
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      last = i;
      ++as;
    } else {
      a += s[i];
    }
  }
  int cnt = (int)a.size();
  std::string b = a.substr(0,cnt/2);
  if (cnt%2==1 || last-as+1>cnt/2 || b+b != a) {
    std::cout << ":(\n";
    return;
  }
  int i = 0;
  cnt /= 2;
  while (as != 0 || cnt != 0) {
    if (s[i] == 'a') {
      as--;
    } else {
      cnt--;
    }
    ++i;
  }
  std::cout << s.substr(0,i) << "\n";
}

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  int as = std::count(s.begin(), s.end(), 'a');
  if ((n-as)%2==1) {
    std::cout << ":(\n";
    return;
  }
  std::string a = s.substr(0, as + (n-as)/2);
  std::string b = "";
  for (char c: a) if (c != 'a') b += c;
  std::cout << (a+b == s ? a : ":(") << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
