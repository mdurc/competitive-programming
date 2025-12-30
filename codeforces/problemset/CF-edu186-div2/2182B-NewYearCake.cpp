#include <bits/stdc++.h>

void solve1() {
  int a, b;
  std::cin >> a >> b;

  std::vector<int> evens(22,0), odds(22,0);
  int at = -1, bt = -1;
  int ab = -1, bb = -1;
  for (int i = 0; i < 22; ++i) {
    if (i % 2 == 0) {
      evens[i] = (i == 0) ? 1 : evens[i-2] + (1 << i);
      if (at == -1 && evens[i] > a) {
        at = i-2;
      }
      if (bt == -1 && evens[i] > b) {
        bt = i-2;
      }
    } else  {
      odds[i] = (i == 1) ? 2 : odds[i-2] + (1 << i);
      if (ab == -1 && odds[i] > a) {
        ab = std::max(0,i-2);
      }
      if (bb == -1 && odds[i] > b) {
        bb = std::max(0,i-2);
      }
    }
  }

  int one = std::min(at,bb)+1;
  if (at != bb) one++;
  int two = std::min(bt,ab)+1;
  if (bt != ab) two++;
  std::cout << std::max(one, two) << "\n";
}

const int mxn = 11;
int evens[mxn], odds[mxn];
void precompute() {
  for (int i = 0; i < mxn*2; ++i) {
    if (i % 2 == 0) {
      evens[i/2] = (i == 0 ? 1: evens[i/2-1]+(1 << i));
    } else {
      odds[i/2] = (i == 1 ? 2: odds[i/2-1]+(1 << i));
    }
  }
}

void solve() {
  int a, b;
  std::cin >> a >> b;
  int at=0, bt=0, ab=0, bb=0;
  for (int i = 0; i < mxn; ++i) {
    if (evens[i] <= a) at = i*2;
    if (evens[i] <= b) bt = i*2;
    if (odds[i] <= a) ab = i*2+1;
    if (odds[i] <= b) bb = i*2+1;
  }
  std::cout << std::max(std::min(at,bb)+(at==bb?1:2),
                        std::min(bt,ab)+(bt==ab?1:2)) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  precompute();
  while (t--) {
    solve();
  }

  return 0;
}
