#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> inc(n);
  vector<int> dec(n);
  for (int i = 0; i < n; ++i) {
    inc[i] = 1;
    dec[i] = 1;
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i]) {
        inc[i] = max(inc[i], inc[j] + 1);
        ans = max(ans, inc[i]);
      }
      if (a[j] > a[i]) {
        dec[i] = max(dec[i], dec[j] + 1);
        ans = max(ans, dec[i]);
      }
    }
  }

  cout << ans << "\n";

  // cout << max(*max_element(inc.begin(), inc.end()),
  //             *max_element(dec.begin(), dec.end())) << "\n";

  return 0;
}
