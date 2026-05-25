#include <bits/stdc++.h>

int mex(const std::vector<int>& v) {
  int n = (int)v.size();
  std::vector<char> used(n + 1, 0);
  for (int x : v) {
    if (x >= 0 && x <= n) used[x] = 1;
  }
  for (int i = 0; i <= n; ++i) {
    if (!used[i]) return i;
  }
  return n;
}

std::vector<int> sprague(int N, const std::vector<int>& moves) {
  std::vector<int> sg(N + 1, 0); // dp with base [0] = 0
  for (int x = 1; x <= N; ++x) {
    std::vector<int> nxt;
    for (int mv : moves) {
      if (x - mv >= 0) nxt.push_back(sg[x - mv]);
    }
    // grundy = mex{grundy values}
    sg[x] = mex(nxt);
  }
  return sg;
}

int nim_sum(const std::vector<int>& v) {
  int x = 0;
  for (int g : v) x ^= g;
  return x;
}
