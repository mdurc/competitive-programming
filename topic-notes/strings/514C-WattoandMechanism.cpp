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
  H change_char(H h1, int pos, char newc, char oldc) {
    // each character contributes [char_value * P^(n-pos-1)]
    return h1 - pow[n-pos-1] * (oldc-'a'+1) + pow[n-pos-1] * (newc-'a'+1);
  }
};

H hashString(std::string& s) { H h; for(char c: s) h=h*C+c; return h; }

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::set<ull> hashset;
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    hashset.insert(hashString(s).get());
  }

  while (m--) {
    std::string s;
    std::cin >> s;
    HashInterval hi(s);
    bool flag = false;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
      for (char ch: {'a', 'b', 'c'}) {
        if (s[i] == ch) continue;
        ull newhash = hi.change_char(hi.get(0,sz-1), i, ch, s[i]).get();
        if (hashset.find(newhash) != hashset.end()) flag = true;
      }
      if (flag) break;
    }
    std::cout << (flag ? "YES\n" : "NO\n");
  }
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
