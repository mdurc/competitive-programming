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
    string a;
    cin >> a;
    vector<int> ps(n+1);
    ps[0] = 0;
    for (int i = 1; i <= n; ++i) ps[i] = ps[i-1] + (a[i-1]-'0');

    int cur = 0;
    int bst = INT_MAX;
    int ans = 0;
    while (cur <= n) {
      if ((cur-ps[cur]) >= (cur+1)/2 && ps[n]-ps[cur] >= (n-cur+1)/2) {
        int amt = abs((double)n/2.0 - cur);
        if (amt < bst) {
          bst = amt;
          ans = cur;
        }
      }
      ++cur;
    }
    cout << ans << "\n";
  }

  return 0;
}
