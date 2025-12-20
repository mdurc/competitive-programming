#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;

    int pa = 0, pb = 0;
    for (char c: a) pa += c == 'P';
    for (char c: b) pb += c == 'P';

    if (pa != pb) {
      cout << "NO\n";
      continue;
    }

    int na = a.size(), nb = b.size();
    int i = na - 1, j = nb - 1;
    while (i >= 0 && a[i] == 'N') i--;
    while (j >= 0 && b[j] == 'N') j--;
    if (na-i-1 == nb-j-1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
