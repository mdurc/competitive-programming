#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool has(ll a) {
  while (a > 0) {
    if (a % 10 == 7) {
      return true;
    }
    a /= 10;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  n += 1;
  int count = 0;
  while (count < 10) {
    if (n % 7 == 0 || has(n)) {
      cout << n << "\n";
      ++count;
    }
    ++n;
  }

  return 0;
}
