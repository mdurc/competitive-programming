#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n*2), freq(n*2+1, 0);
  for (int i = 0; i < n*2; ++i) {
    std::cin >> a[i];
    freq[a[i]]++;
  }
  int cnt_o = 0, cnt_e = 0;
  for (int i = 1; i <= n*2; ++i) {
    if (freq[i] == 0) continue;
    if (freq[i]%2 != 0) {
      cnt_o++;
    } else {
      cnt_e++;
    }
  }
  int k = std::min(cnt_e, n);
  if (cnt_o == 0 && k%2 != n%2) {
    k--;
  }
  std::cout << cnt_o+k*2 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
