#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int k, x;
    cin >> k >> x;
    int n = 1;
    while (true) {
      bool ok = 1;
      for (int r = 1; r+x <= n; ++r) {
        int amt = 1;
        int z = r+x;
        while (z <= n) {
          ++amt;
          z+=x;
        }
        if (amt > k) {
          ok = 0;
        }
      }
      if (!ok) break;
      ++n;
    }
    cout << n << "\n";
  }

  return 0;
}
