// https://codeforces.com/problemset/problem/768/E
#include <bits/stdc++.h>
using namespace std;
#define first() { cout << "NO\n"; exit(0); }
#define second() { cout << "YES\n"; exit(0); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // last move wins: normal play
  // can second player win?

  int n;
  cin >> n;

  if (n == 1) first();

  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
  }

  // dp[4] = [1,2,3]

  return 0;
}
