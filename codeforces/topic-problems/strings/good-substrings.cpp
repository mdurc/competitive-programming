#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef unsigned long long ll; // MOD 2e64 on overflow
#define mp make_pair

const int mxn = 1505;
const int P1 = 131;
int n;
ll pows[mxn];
ll hash_f[mxn];

void precompute_pows() {
  pows[0] = 1;
  for (int i = 1; i < mxn; ++i) pows[i] = pows[i-1] * P1;
}

void gen(string& s) {
  hash_f[0] = 0;
  for (int i = 0; i < n; ++i) {
    hash_f[i+1] = hash_f[i] * P1 + (s[i]-'a'+1);
  }
}

// 0-based indexing
ll get(int l, int r) {
  return hash_f[r+1] - (hash_f[l] * pows[r-l+1]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // good if <= k bad
  // find # distinct good substring of s

  string s, g;
  int k;
  cin >> s >> g >> k;
  n = s.size();

  bool good[26];
  for (int i = 0; i < 26; ++i) good[i] = g[i] == '1';

  precompute_pows();
  gen(s);

  unordered_set<ll> hashes;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for(int j = i; j < n; ++j){
      if(!good[s[j]-'a'] && ++cnt > k) break;
      hashes.insert(get(i, j));
    }
  }

  cout << hashes.size() << "\n";

  return 0;
}
