// https://codeforces.com/problemset/problem/126/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxn = 1e6 + 5;
const int MOD = 1e9 + 9, P1 = 31;

string s;
int n;
ll hash_f[mxn];
ll pow_p[mxn];
vector<int> v;

void precompute() {
  pow_p[0] = 1;
  for (int i = 1; i < mxn; ++i) pow_p[i] = (pow_p[i-1] * P1) % MOD;
}

void compute_hash() {
  hash_f[0] = 0;
  for (int i = 0; i < n; ++i) {
    hash_f[i + 1] = ((hash_f[i] * P1) % MOD + (s[i]-'a'+1)) % MOD;
  }
}

// 0-based indexing
ll get(int l, int r) {
  return ((hash_f[r+1] - (hash_f[l] * pow_p[r-l+1])% MOD) + MOD) % MOD;
}

bool has_infix(int k) {
  ll h1 = get(0, k - 1);
  for (int i = 1; i < n - k; ++i) {
    if (h1 == get(i, i + k - 1)) {
      return true;
    }
  }
  return false;
}

void find_possible_lens() {
  // find prefix and suffix lengths
  for (int i = 0; i < n; ++i) {
    if (get(0, i) == get(n-i-1, n - 1)) {
      v.push_back(i + 1);
    }
  }
}

void solve() {
  int ans = 0;
  // of the possible prefix lengths in v, find the maximum length that has infix
  // thus we need the upper bound
  int l = 0, r = v.size() - 1;
  while (l < r) {
    // +1 to select the right middle for even ranges
    // necessary because we are moving left to mid, avoiding infinite loop
    int mid = l + (r - l + 1) / 2;
    if (has_infix(v[mid])) {
      l = mid; // upper bound
    } else {
      r = mid - 1;
    }
  }

  if (has_infix(v[l])) {
    cout << s.substr(0, v[l]) << "\n";
  } else {
    cout << "Just a legend" << "\n";
  }
}

int main() {
  cin >> s;
  n = s.size();
  compute_hash();
  precompute();
  find_possible_lens();
  solve();
}
