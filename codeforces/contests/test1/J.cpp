#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  string rep;
  cin >> rep;
  return (rep == "YES");
}

void answer(int a) {
  cout << "! " << a << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  // 1 2 3 4 5
  // l       r
  //     m
  // l r
  // m

  // [1 2] [3 4] [5 6] [7 8] 9 [10 11]
  // 1 2 3 4 5 6 7 8 9 10 11
  // l   m   r
  // [1 2] 3 [4 5] [6 7] [8
  // 1 [2 3] [4 5] [6 7] [8 9] [10 11]
  //             l   m     r

  int l = 1;
  int r = n;
  // 1 [2 3] [4 5] [6 7] [8 9]
  // 1 2 3 4 5 6 7 8 9
  // l       m   l r

  while (l < r) {
    int mid = l + (r - l) / 2;
    if (mid % 2 == 0) --mid;
    if (query(mid, mid + 1)) {
      l = mid + 2;
    } else {
      r = mid;
    }
  }

  answer(l);

  return 0;
}
