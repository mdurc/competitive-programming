#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;

  int dist = 0;
  std::set<int> seen;
  std::queue<int> q;
  q.push(n);
  seen.insert(n);
  while (!q.empty()) {
    int sz = (int)q.size();
    for (int i = 0; i < sz; ++i) {
      int u = q.front(); q.pop();
      if (u == k) {
        std::cout << dist << "\n";
        return;
      }
      if (u < k) continue;
      if (seen.find(u/2) == seen.end()) {
        seen.insert(u/2);
        q.push(u/2);
      }
      if (seen.find((u+1)/2) == seen.end()) {
        seen.insert((u+1)/2);
        q.push((u+1)/2);
      }
    }
    ++dist;
  }
  std::cout << "-1\n";
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
