#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

const int mxn = 2e5+5;
int n, x, a[mxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    int pos = -1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == x) {
        pos = i;
      }
    }
    int l = 1, r = n + 1;
    while (r - l != 1) {
      int m = l + (r - l) / 2;
      if (a[m] <= x) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << "1\n";
    cout << pos << " " << l << "\n";
  }

  return 0;
}
