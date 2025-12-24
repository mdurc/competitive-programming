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
    int n;
    cin >> n;
    cout << (1 << n) - 1;
    for (int i = n - 1; i >= 0; --i) {
      int mask = (1 << i) - 1;
      int step = (1 << (i + 1));
      int lim = (1 << n);
      for (int x = mask; x < lim; x += step) {
        cout << " " << x;
      }
    }
    cout << "\n";
  }

  return 0;
}
