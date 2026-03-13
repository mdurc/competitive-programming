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
    int a, b, c;
    cin >> a >> b >> c;
    if (b % 3 != 0 && c < (3 - b%3)) {
      cout << "-1\n";
      continue;
    }
    if (b % 3 != 0) c -= (3-(b%3));
    cout << a + (b+2)/3 + ((c/3) + ((c%3)/2) + ((c%3)%2)) << "\n";
  }

  return 0;
}
