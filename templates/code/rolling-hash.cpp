#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int P1 = 31; // P2 = 37; // 131 // 1315423911ULL
int M1 = 1e9 + 7; // M2 = 1e9 + 9; // or no MOD with unsigned long long
const int mxn = 1e6 + 5;
string s; int n;
ll hash_f[mxn]; // forward hashes: hash of substring of length i
ll hash_r[mxn]; // reverse hashes
ll pow_p1[mxn]; // precomuted powers for substring hashes
void precompute() {
  pow_p1[0] = 1;
  for (int i = 1; i < mxn; ++i) pow_p1[i] = (pow_p1[i-1] * P1) % M1;
}
ll compute_hash() {
  // forward hashes: s[0]*p^n + s[1]*p^(n-1) + s[2]*p^(n-2) .. mod m
  hash_f[0] = hash_r[n] = 0;
  for (int i = 0; i < n; ++i) {
    hash_f[i + 1] = ((hash_f[i] * P1)%M1 + (s[i]-'a'+1)) % M1;
  }
  for (int i = n - 1; i >= 0; --i) {
    hash_r[i] = ((hash_r[i + 1] * P1)%M1 + (s[i]-'a'+1)) % M1;
  }
  return hash_f[n]; // full string hash
}
ll change_char(ll h1, int pos, char newc, char oldc) {
  // Each character contributes [char_value * P^(n-pos-1)]
  ll exp = pow_p1[n-pos-1];
  return ((h1 - ((oldc-'a'+1) * exp)%M1 + ((newc-'a'+1) * exp)%M1) + M1) % M1;
}
ll get(int l, int r, bool get_fwd = true) { // 0-based indexing
  ll fwd = ((hash_f[r+1] - (hash_f[l] * pow_p1[r-l+1])%M1) + M1) % M1;
  ll rev = ((hash_r[l] - (hash_r[r+1] * pow_p1[r-l+1])%M1) + M1) % M1;
  return get_fwd ? fwd : rev;
}
bool is_palindrome(int l, int r) { return get(l,r) == get(l,r,0); }
bool has_infix(int len) {
  ll h1 = get(0, len - 1);
  for (int i = 1; i < n - len; ++i) {
    if (h1 == get(i, i+len-1)) return true;
  }
  return false;
}
vector<int> prefix_suffixes() {
  vector<int> res; // prefix lengths that are also suffixes
  for (int i = 0; i < n; ++i) {
    if (get(0, i) == get(n-i-1, n - 1)) {
      res.push_back(i + 1);
    }
  }
  return res;
}
