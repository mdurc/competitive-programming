#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://cses.fi/problemset/task/1676

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  DSU ds(n);
  int mx = 1;
  int cmp = n;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if (!ds.same(a, b)) {
      ds.merge(a, b);
      --cmp;
      mx = max(mx, ds.size[ds.find(a)]);
    }
    cout << cmp << " " << mx << "\n";
  }

  return 0;
}
