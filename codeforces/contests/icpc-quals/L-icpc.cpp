#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> amts(n);
  for (int i = 0; i < n; ++i) {
    cin >> amts[i];
  }

  int a = amts[0] / 3;
  int b = amts[1] - 2 * a;
  int c = amts[n - 1] / 3;
  cout << a << " " << b << " " << c << "\n";

  return 0;
}
