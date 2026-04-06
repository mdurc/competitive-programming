#include <bits/stdc++.h>

void solve() {
  int tp, td, n;
  std::cin >> tp >> td >> n;
  std::map<int,std::vector<std::pair<int,int>>> days;
  for (int i = 0; i < n; ++i) {
    int p1, p2, d;
    std::cin >> p1 >> p2 >> d;
    days[d].emplace_back(p1, p2);
  }
  std::map<int, std::set<int>> sick;
  for (int i = 1; i <= 3; ++i) {
    sick[0].insert(i);
  }
  for (auto&[d, p]: days) {
    std::vector<int> next;
    for (auto&[p1,p2]: p) {
      bool p1_sick = sick[p1].count(d);
      bool p2_sick = sick[p2].count(d);
      if (p1_sick && !p2_sick) next.push_back(p2);
      if (p2_sick && !p1_sick) next.push_back(p1);
    }
    for (int x: next) {
      for (int i = 1; i <= 3; ++i) {
        sick[x].insert(d+i);
      }
    }
  }
  std::cout << (sick[tp].count(td) ? "true\n" : "false\n");
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
