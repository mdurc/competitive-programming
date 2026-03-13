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
    string s;
    cin >> n >> s;
    bool f1 = 0;
    int pref = 0, cnt = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      if (!f1) {
        if (s[i] == '0') {
          ++pref;
        } else {
          f1 = 1;
        }
      } else {
        if (s[i] == '0') {
          ++cnt;
        } else {
          cnt = 0;
        }
      }
      res = max(res, cnt);
    }
    cout << max(res, pref + cnt) << "\n";
  }

  return 0;
}
