#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;

// using H = unsigned long long; // for no anti-hash test cases (2x faster)
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (u128)x * o.x; return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11+3;
// static H C;
struct HashInterval {
  int n;
  std::vector<H> hash_f, hash_r; // hash of substring of length i
  std::vector<H> pow;
	HashInterval(std::string& s) :
    n((int)s.size()), hash_f(n+1), hash_r(n+1), pow(hash_f) {
		pow[0] = 1;
    for (int i = 0; i < n; ++i) {
      // forward hashes: s[0]*p^n + s[1]*p^(n-1) + s[2]*p^(n-2) .. mod m
      hash_f[i+1] = hash_f[i] * C + s[i];
      hash_r[n-i-1] = hash_r[n-i] * C + s[n-i-1];
      pow[i+1] = pow[i] * C;
    }
	}
	ull get(int l, int r, bool get_fwd = true) { // hash [a, b] -- 0 based
    H fwd = hash_f[r+1] - hash_f[l] * pow[r-l+1];
    H rev = hash_r[l] - hash_r[r+1] * pow[r-l+1];
		return get_fwd ? fwd.get() : rev.get();
	}
};

void solve() {
  std::string s, g;
  int k;
  std::cin >> s >> g >> k;
  int n = (int)s.size();

  bool good[26];
  for (int i = 0; i < 26; ++i) good[i] = g[i] == '1';

  HashInterval hi(s);

  std::unordered_set<ull> hashes;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for(int j = i; j < n; ++j){
      if(!good[s[j]-'a'] && ++cnt > k) break;
      hashes.insert(hi.get(i, j));
    }
  }

  std::cout << hashes.size() << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
