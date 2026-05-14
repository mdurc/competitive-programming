#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
      DSU dsu(n);
      for (auto& r : roads) dsu.merge(r[0], r[1]);

      int root1 = dsu.find(1);
      int ans = INT_MAX;
      for (auto& r : roads)
          if (dsu.find(r[0]) == root1) ans = min(ans, r[2]);
      return ans;
    }
};
