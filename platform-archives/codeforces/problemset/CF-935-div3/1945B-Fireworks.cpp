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
    ll a, b, m;
    cin >> a >> b >> m;
    cout << m/a + m/b + 2 << "\n";
  }

  return 0;
}
