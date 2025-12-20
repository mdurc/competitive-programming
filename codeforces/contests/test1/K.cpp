#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  // min heap
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    pq.push(a);
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ll val = pq.top();
    pq.pop();
    val += pq.top();
    pq.pop();
    pq.push(val);
    ans += val;
  }

  cout << ans << "\n";

  return 0;
}
