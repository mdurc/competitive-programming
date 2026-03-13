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
    ll x, y;
    string s;
    cin >> n >> x >> y >> s;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    int sum = accumulate(all(p), 0);
    if (sum > x + y) {
      cout << "NO\n";
      continue;
    }

    ll mnAVotes = 0;
    ll aWinsEvenVotes = 0;
    ll mnBVotes = 0;
    ll bWinsEvenVotes = 0;
    bool awins = 0, bwins = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        awins = 1;
        mnAVotes += (p[i] / 2) + 1; // majority to win
        if (p[i] % 2 == 0) {
          aWinsEvenVotes++;
        }
      } else {
        bwins = 1;
        mnBVotes += (p[i] / 2) + 1;
        if (p[i] % 2 == 0) {
          bWinsEvenVotes++;
        }
      }
    }

    if (mnAVotes > x || mnBVotes > y) {
      cout << "NO\n";
      continue;
    }

    ll max_KA = 0;
    if (awins) {
      ll extraA = x - mnAVotes;
      max_KA = aWinsEvenVotes + 2 * extraA;
    } else {
      max_KA = 0;
    }

    ll max_KB = 0;
    if (bwins) {
      ll extraB = y - mnBVotes;
      max_KB = bWinsEvenVotes + 2 * extraB;
    } else {
      max_KB = 0;
    }

    ll extra = (x + y) - sum;
    cout << ((max(0LL, extra - max_KB) <= min(extra, max_KA)) ? "YES\n" : "NO\n");
  }

  return 0;
}
