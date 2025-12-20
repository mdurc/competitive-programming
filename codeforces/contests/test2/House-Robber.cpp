#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  ll n, k;
  cin >> n >> k;
  map<ll, ll> loc_val;
  for (int i = 0; i < n; ++i) {
    int pos, val;
    cin >> pos >> val;
    loc_val[pos] += val;
  }
  vector<pair<ll, ll>> real_vals;
  for (const auto& [d, v]: loc_val) real_vals.push_back({d,v});

  ll idx = lower_bound(real_vals.begin(), real_vals.end(), pair<ll,ll>({0,0})) - real_vals.begin();
  n = real_vals.size();

  map<ll,ll> pos_mem, neg_mem;
  {
    ll cs = 0;
    for (int i = idx; i < n; ++i) {
      cs += real_vals[i].second;
      pos_mem[real_vals[i].first] = cs;
    }
  }
  {
    ll cs = 0;
    for (int i = idx - 1; i >= 0; i--) {
      cs += real_vals[i].second;
      neg_mem[real_vals[i].first] = cs;
    }
  }

  ll maxi = 0;
  for (const auto& [d,v]: pos_mem) {
    if (d > k) break;
    maxi = max(maxi, v);
    auto it = neg_mem.upper_bound(k-2*d);
    if (it == neg_mem.begin()) continue;
    --it;
    maxi = max(maxi, it->second + v);
  }
  for (const auto& [d,v]: neg_mem) {
    if (d > k) break;
    maxi = max(maxi, v);
    auto it = pos_mem.upper_bound(k-2*d);
    if (it == pos_mem.begin()) continue;
    --it;
    maxi = max(maxi, it->second + v);
  }
  cout << maxi << endl;
}
