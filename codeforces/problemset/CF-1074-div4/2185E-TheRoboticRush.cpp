#include <bits/stdc++.h>

const int inf = 2e9+5;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];
  std::sort(b.begin(), b.end());
  std::string s;
  std::cin >> s;
  std::vector<std::tuple<int,int,int>> near(n);
  for (int i = 0; i < n; ++i) {
    auto itr = std::upper_bound(b.begin(), b.end(), a[i]);
    int dl = (itr == b.begin()) ? inf : a[i] - *(itr-1);
    int dr = (itr == b.end()) ? inf : *itr - a[i];
    near[i] = std::make_tuple(dl, dr, i);
  }
  std::vector<std::tuple<int,int,int>> near_right = near;
  std::sort(near.begin(), near.end());
  std::sort(near_right.begin(), near_right.end(), [](const auto& x, const auto& y){
      return std::get<1>(x) < std::get<1>(y);
      });
  std::vector<int> ps(k);
  ps[0] = (s[0] == 'R' ? 1: -1);
  for (int i = 1; i < k; ++i) {
    if (s[i] == 'R') {
      ps[i] = ps[i-1] + 1;
    } else {
      ps[i] = ps[i-1] - 1;
    }
  }
  std::vector<bool> dead(n, false);
  int alive = n, mx_l = 0, mx_r = 0;
  int l = 0, r = 0;
  for (int i = 0; i < k; ++i) {
    int cur = ps[i];
    if (cur < 0) mx_l = std::max(mx_l, -cur);
    else mx_r = std::max(mx_r, cur);
    while(l < n && std::get<0>(near[l]) <= mx_l) {
      int id = std::get<2>(near[l]);
      if (!dead[id]) {
        dead[id] = true;
        alive--;
      }
      l++;
    }
    while(r < n && std::get<1>(near_right[r]) <= mx_r) {
      int id = std::get<2>(near_right[r]);
      if (!dead[id]) {
        dead[id] = true;
        alive--;
      }
      r++;
    }
    std::cout << alive << " ";
  }
  std::cout << "\n";
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
