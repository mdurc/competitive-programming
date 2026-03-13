#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

ll bpow(ll a, ll b, ll mod) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

int P1 = 31, P2 = 37;
int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int mxn = 6e5 + 7;
pi getHash(const string &s) {
  ll h1=0, h2=0;
  for (char c : s) {
    h1 = (h1*P1 + c) % MOD1;
    h2 = (h2*P2 + c) % MOD2;
  }
  return {h1,h2};
}
pi change_char(pi oldhash, int pos, char newchar, char oldchar, int n) {
  // Each character contributes [char_value * P^(n-pos-1)]
  pi newhash = oldhash;
  ll exp1 = bpow(P1, n-pos-1, MOD1);
  ll exp2 = bpow(P2, n-pos-1, MOD2);
  // replace the old char contribution with new char contribution
  newhash.first = (oldhash.first - oldchar * exp1 + newchar * exp1) % MOD1;
  if (newhash.first < 0) newhash.first += MOD1;
  newhash.second = (oldhash.second - oldchar * exp2 + newchar * exp2) % MOD2;
  if (newhash.second < 0) newhash.second += MOD2;

  // or with correct modulus:
  // newhash.first = ((oldhash.first - (oldchar * exp1)%MOD1 + (newchar * exp1)%MOD1) + MOD1) % MOD1;
  // newhash.second = ((oldhash.second - (oldchar * exp2)%MOD2 + (newchar * exp2)%MOD2) + MOD2) % MOD2;
  return newhash;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  set<pi> hashset;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    hashset.insert(getHash(s));
  }

  while (m--) {
    string s;
    cin >> s;
    pi oldhash = getHash(s);
    bool flag = false;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      for (char ch: {'a', 'b', 'c'}) {
        if (s[i] == ch) continue;
        pi newhash = change_char(oldhash, i, ch, s[i], n);
        if (hashset.find(newhash) != hashset.end()) flag = true;
      }
      if (flag) break;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
