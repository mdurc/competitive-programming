#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, k;
vector<int> a;

bool bump(vector<int>& a) {
  vector<int> inc(n, 1);
  vector<int> dec(n, 1);
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
      if (ans > k) return false;
    }
  }
  return ans <= k;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    a.push_back(i);
  }

  bool found = false;
  vector<int> result;
  do {
    if (bump(a)) {
      found = true;
      result = a;
      break;
    }
  } while (next_permutation(a.begin(), a.end()));

  if (found) {
    cout << "Possible\n";
    for (int i = 0; i < n; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "Impossible\n";
  }

  return 0;
}
