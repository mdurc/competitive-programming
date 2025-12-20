#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// z[i] is the length of the longest substring starting at i that is prefix s
vector<int> z_function(const string& s) {
  int n = s.size();
  vector<int> z(n, 0);
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i <= R) z[i] = min(R - i + 1, z[i - L]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > R) {
      L = i;
      R = i + z[i] - 1;
    }
  }
  return z;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  if (s == t) {
    cout << "0\n";
    return 0;
  }

  int n = s.size();
  string u = s + s;
  string p = t + "#" + u;
  vector<int> z = z_function(p);

  vector<int> matches;
  for (int j = 0; j < n; j++) {
    int i = j + n + 1;
    if (z[i] >= n) {
      matches.push_back(j);
    }
  }

  if (!matches.empty()) {
    int max_idx = -1;
    for (int idx : matches) {
      if (idx > 0 && idx > max_idx) {
        max_idx = idx;
      }
    }
    if (max_idx != -1) {
      cout << n - max_idx << "\n";
    } else {
      cout << n << "\n";
    }
    return 0;
  }

  cout << "-1\n";
}
