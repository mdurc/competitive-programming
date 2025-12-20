#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c, n;
  cin >> r >> c >> n;

  vector<pi> coords(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    coords[i] = {x - 1, y - 1};
  }

  vector<vector<pi>> closest(r, vector<pi>(c, {-1, -1}));
  vector<vector<pi>> dists(r, vector<pi>(c, {INT_MAX, INT_MAX}));

  queue<tuple<int, int, int, int>> q;
  for (int i = 0; i < n; ++i) {
    int x = coords[i].first;
    int y = coords[i].second;
    dists[x][y] = {0, INT_MAX};
    closest[x][y] = {i, -1};
    q.push({x, y, i, 0});
  }

  vector<pi> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [x, y, tower, distance] = q.front();
    q.pop();

    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (tower == closest[nx][ny].first || tower == closest[nx][ny].second)
        continue;

      int curr = distance + 1;
      int df = dists[nx][ny].first;
      int ds = dists[nx][ny].second;
      if (curr < df || (curr == df && tower < closest[nx][ny].first)) {
        dists[nx][ny] = {curr, df};
        closest[nx][ny] = {tower, closest[nx][ny].first};
        q.push({nx, ny, tower, curr});
      } else if (curr < ds || (curr == ds && tower < closest[nx][ny].second)) {
        dists[nx][ny] = {dists[nx][ny].first, curr};
        closest[nx][ny].second = tower;
        q.push({nx, ny, tower, curr});
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << closest[i][j].first + 1 << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << closest[i][j].second + 1 << " ";
    }
    cout << "\n";
  }

  return 0;
}
