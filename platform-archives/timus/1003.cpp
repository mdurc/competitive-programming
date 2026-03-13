#include <bits/stdc++.h>

std::map<int, int> parent;
std::map<int, int> state;

int find(int v) {
  if (parent.find(v) == parent.end()) return parent[v] = v, state[v] = 0, v;
  if (v == parent[v]) return v;
  int old = parent[v];
  int nxt = find(parent[v]); // compress
  state[v] = state[v] ^ state[old];
  return parent[v] = nxt;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int len;
  while (std::cin >> len) {
    if (len == -1) break;
    int q;
    std::cin >> q;
    parent.clear(), state.clear();
    int res = -1;
    for (int i = 1; i <= q; ++i) {
      int a, b;
      std::string s;
      std::cin >> a >> b >> s;
      if (res != -1) continue;
      int parity = (s == "odd" ? 1 : 0);
      int ra = find(a-1);
      int rb = find(b);
      if (ra == rb) {
        if ((state[a-1] ^ state[b]) != parity) {
          res = i - 1;
        }
      } else {
        parent[ra] = rb;
        state[ra] = state[a-1] ^ state[b] ^ parity;
      }
    }

    std::cout << (res == -1 ? q : res) << "\n";
  }

  return 0;
}
