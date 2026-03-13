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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mn = *min_element(all(a));

    auto cond = [&](int k) {
      // can we reduce every element to equal mn
      for (int x : a) {
        if (x == mn) continue;
        if ((x - mn) < k) {
          return false;
        }
      }
      return true;
    };

    int l = mn, r = *max_element(all(a));
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (cond(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }

  return 0;
}
