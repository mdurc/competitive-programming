#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k % 2 == 1) {
      for (int i = 0; i < k; ++i) cout << n << " ";
      cout << "\n";
      continue;
    }

    vector<int> a(k);
    int small = 0;
    for (int b = 30; b >= 0; --b) {
      int cur = 1 << b;
      if (n & cur) {
        // include odd number of times
        if (small < k) ++small;
        for (int i = 0; i < k; ++i) {
          if (i == small - 1) continue;
          a[i] += cur;
        }
      } else {
        // include even number of times on the small values
        for (int i = 0; i < small / 2 * 2; ++i) {
          a[i] += cur;
        }
      }
    }
    for (int i = 0; i < k; i++) cout << a[i] << " ";
    cout << "\n";
  }

  return 0;
}
