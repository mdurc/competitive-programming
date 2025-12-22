#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  ll k;
  cin >> n >> k;

  vector<pl> left, right;
  ll free = 0;
  for (int i = 0; i < n; ++i) {
    ll x, v;
    cin >> x >> v;
    if (x < 0) {
      left.push_back({-x, v});
    } else if (x > 0) {
      right.push_back({x, v});
    } else {
      free = v;
    }
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  int nl = left.size(), nr = right.size();
  vector<ll> psl(nl + 1, 0), psr(nr + 1, 0);
  for (int i = 1; i <= nl; ++i) psl[i] = psl[i - 1] + left[i - 1].second;
  for (int i = 1; i <= nr; ++i) psr[i] = psr[i - 1] + right[i - 1].second;

  ll ans = 0;

  // left first (or all right)
  for (int i = 0; i <= nl; ++i) {
    ll costL = (i == 0 ? 0 : left[i - 1].first);
    ll back_cost = 2 * costL;
    if (back_cost > k) break;

    ll rem = k - back_cost;
    pl target = make_pair(rem, LLONG_MAX);
    int idx = upper_bound(right.begin(), right.end(), target) - right.begin();
    ans = max(ans, psl[i] + psr[idx]);
  }

  // right first (or all left)
  for (int i = 0; i <= nr; ++i) {
    ll costR = (i == 0 ? 0 : right[i - 1].first);
    ll back_cost = 2 * costR;
    if (back_cost > k) break;

    ll rem = k - back_cost;
    pl target = make_pair(rem, LLONG_MAX);
    int idx = upper_bound(left.begin(), left.end(), target) - left.begin();
    ans = max(ans, psr[i] + psl[idx]);
  }

  cout << ans + free << "\n";

  return 0;
}
