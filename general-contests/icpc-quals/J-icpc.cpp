#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> count(11, 0);
  vector<int> order(11, 0);
  for (int i = 0; i < 100; ++i) {
    int j;
    cin >> j;
    int idx = j % 10;
    if (idx == 0) {
      idx = 10;
    }

    if (count[idx] < 10) {
      if (++count[idx] == 10) order[idx] = i;
    }
  }

  int a = 1;
  for (int i = 2; i <= 10; ++i) {
    if (order[i] > order[a]) {
      a = i;
    }
  }
  cout << a << "\n";

  return 0;
}
