#include <bits/stdc++.h>

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int mid_len = y-x;
  std::vector<int> mid(mid_len);
  int min_pos = (std::min_element(a.begin()+x,a.begin()+y)-a.begin()) - x;
  for (int i = min_pos; i-min_pos < mid_len; ++i) {
    mid[i-min_pos] = a[(i%mid_len) + x];
  }

  std::vector<int> outer(n-mid_len);
  for (int i = 0; i < x; ++i) outer[i] = a[i];
  for (int i = y; i < n; ++i) outer[i-y+x] = a[i];

  int end_outer = 0;
  for (; end_outer < n-mid_len; ++end_outer) {
    if (outer[end_outer] < mid[0]) {
      std::cout << outer[end_outer] << " ";
    } else {
      break;
    }
  }
  for (int i = 0; i < mid_len; ++i) std::cout << mid[i] << " ";
  for (int i = end_outer; i < n-mid_len; ++i) std::cout << outer[i] << " ";

  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
