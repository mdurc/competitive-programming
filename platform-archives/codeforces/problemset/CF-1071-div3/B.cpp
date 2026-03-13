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

    int start = 0;
    for (int i = 0; i+1 < n; ++i) {
      start += abs(a[i] - a[i+1]);
    }

    int bst = abs(a[0]-a[1]);
    for (int i = 1; i < n; ++i) {
      int amt = 0;
      if (i == n-1) {
        amt = abs(a[i-1] - a[i]);
      } else {
        amt = (abs(a[i-1]-a[i]) + abs(a[i]-a[i+1])) - abs(a[i-1]-a[i+1]);
      }
      if (amt > bst) {
        bst = amt;
      }
    }
    cout << start - bst << "\n";
  }

  return 0;
}
