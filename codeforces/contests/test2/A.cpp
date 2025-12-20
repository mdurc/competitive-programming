#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

const int mxn = 1e5 + 1;
int n;
int w[mxn];
vector<int> adj[mxn];

bool visited[mxn];
int sz[mxn];
int dfs(int a) {
  visited[a] = true;
  sz[a] = 1;
  for (int b : adj[a]) {
    if (!visited[b]) {
      sz[a] += dfs(b);
    }
  }
  return sz[a];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n-1; ++i) {
    cin >> w[i];
  }
  sort(w, w+n-1);
  reverse(w, w+n-1);

  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  // cost [a][b] = w[a][b] * sz[b]
  sort(sz+2, sz+n+1); // skip 0 and root(1)
  ll res = 0;
  for (int i = 0; i < n-1; ++i) {
    res += (ll)w[i] * sz[i+2];
  }
  cout << res << "\n";

  return 0;
}
