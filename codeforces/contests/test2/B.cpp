#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 5;
int parent[2*mxn];

int find(int a) {
  if (parent[a] == a) return a;
  return parent[a] = find(parent[a]);
}
bool same(int a, int b) { return find(a) == find(b); }
void merge(int a, int b) {
  if (same(a,b)) return;
  parent[find(a)] = find(b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;

  iota(parent, parent+2*mxn, 0);

  while (c--) {
    int a, b;
    char c;
    cin >> a >> b >> c;

    int ared = a, ablue = a + n;
    int bred = b, bblue = b + n;
    if (c == 'R') {
      merge(ared, bred);
      merge(ablue,bblue);
    } else {
      merge(ared, bblue);
      merge(ablue,bred);
    }
    if (same(ared,ablue)) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}
