#include <bits/stdc++.h>

// using ll = long long;
// using ull = unsigned long long;
// using u128 = unsigned __int128;

// using H = unsigned long long; // for no anti-hash test cases (2x faster)
struct H {
	unsigned long long x; H(unsigned long long x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (unsigned __int128)x * o.x; return H((unsigned long long)m) + (unsigned long long)(m >> 64); }
	unsigned long long get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (long long)1e11+3;
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
	H get(int l, int r, bool get_fwd = true) { // hash [a, b] -- 0 based
    H fwd = hash_f[r+1] - hash_f[l] * pow[r-l+1];
    H rev = hash_r[l] - hash_r[r+1] * pow[r-l+1];
		return get_fwd ? fwd : rev;
	}
  H change_char(H h1, int pos, char newc, char oldc) {
    // each character contributes [char_value * P^(n-pos-1)]
    return h1 - pow[n-pos-1] * (oldc-'a'+1) + pow[n-pos-1] * (newc-'a'+1);
  }
};

// get hashes of all substrings of a given length
std::vector<H> getHashes(std::string& s, int length) {
  int n = (int)s.size();
	if (n < length) return {};
	H h = 0, pow = 1;
  for (int i = 0; i < length; ++i) {
    h = h * C + s[i];
    pow = pow * C;
  }
  std::vector<H> ret = {h};
  for (int i = length; i < n; ++i) {
		ret.push_back(h = h * C + s[i] - pow * s[i-length]);
	}
	return ret;
}

H hashString(std::string& s) { H h; for(char c: s) h=h*C+c; return h; }

int main() {
  // std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  // C = H(rng());
  // while (std::gcd(C.x, -1ULL) != 1) {
  //   C = H(rng());
  // }
}

/*
// Core hashing technique
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
*/
