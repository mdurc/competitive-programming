#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);
  string res = "";
  for (char c: s) if (isupper(c)) res += c;
  cout << res << "\n";

  return 0;
}
