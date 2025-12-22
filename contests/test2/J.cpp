#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxn = 1e5 + 5;
int depth[mxn];
vector<int> adj[mxn];
ll sz[mxn], max_previsit[mxn];
int n;

void dfs1(int a, int p) {
  for (int b : adj[a]) {
    if (b == p) continue;
    depth[b] = depth[a] + 1;
    dfs1(b, a);
    sz[a] += sz[b];
  }
}

void dfs2(int a, int p) {
  for (int b : adj[a]) {
    if (b == p) continue;
    max_previsit[b] = max_previsit[a] + (sz[a] - sz[b]);
    dfs2(b, a);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  depth[1] = 1;
  max_previsit[1] = 1;
  fill(sz, sz+mxn, 1);
  dfs1(1, 0);
  dfs2(1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << depth[i] << " " << max_previsit[i] << "\n";
  }
}
