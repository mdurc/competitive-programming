#include <bits/stdc++.h>

template <typename T>
constexpr T bpow(T a, unsigned long long n) {
  T res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
template <typename SV>
constexpr static std::pair<SV, SV> invGcd(SV val, SV mod) {
  val %= mod;
  if (val < 0) val += mod;
  if (val == 0) return std::make_pair(mod, 0);
  SV s = mod, t = val;
  SV m0 = 0, m1 = 1;
  while (t) {
    SV u = s / t;
    s -= t * u;
    m0 -= m1 * u;
    std::swap(s, t);
    std::swap(m0, m1);
  }
  if (m0 < 0) m0 += mod / s;
  return std::make_pair(s, m0);
}

template <typename U, U M>
struct Mod {
  static_assert(std::is_unsigned_v<U>, "Mod type should be unsigned");
  using UV = std::conditional_t<sizeof(U) <= 4, unsigned long long, unsigned __int128>;
  using SV = std::conditional_t<sizeof(U) <= 4, long long, __int128>;
  constexpr Mod() : x(0) {}
  template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
  constexpr Mod(T y) {
    if constexpr (std::is_signed_v<T>) {
      using S = std::make_signed_t<U>;
      S v = y % S(mod());
      if (v < 0) v += mod();
      x = v;
    } else {
      x = U(y % mod());
    }
  }
  constexpr static U mod() { return M; }
  // uses invGCD, for coprime mod. if p is prime, fermat's little theorem works a^(mod-2)
  constexpr Mod inv() const { auto v = invGcd((SV)x, (SV)mod()); assert(v.first == 1); return v.second; }
  constexpr explicit operator U() const { return x; }
  constexpr Mod operator-() const { return Mod() -= *this; }
  constexpr Mod operator+(const Mod& rhs) const { return Mod(*this) += rhs; }
  constexpr Mod operator-(const Mod& rhs) const { return Mod(*this) -= rhs; }
  constexpr Mod operator*(const Mod& rhs) const { return Mod(*this) *= rhs; }
  constexpr Mod operator/(const Mod& rhs) const { return Mod(*this) /= rhs; }
  constexpr Mod& operator+=(const Mod& rhs) { return (x += rhs.x) >= mod() ? x -= mod() : x, *this; }
  constexpr Mod& operator-=(const Mod& rhs) { return (x -= rhs.x) >= mod() ? x += mod() : x, *this; }
  constexpr Mod& operator*=(const Mod& rhs) { return x = (UV)x * rhs.x % mod(), *this; }
  constexpr Mod& operator/=(const Mod& rhs) { return *this *= rhs.inv(); }
  constexpr bool operator<(const Mod& rhs) const { return x < rhs.x; }
  constexpr bool operator>(const Mod& rhs) const { return x > rhs.x; }
  constexpr bool operator==(const Mod& rhs) const { return x == rhs.x; }
  constexpr bool operator!=(const Mod& rhs) const { return x != rhs.x; }
  constexpr bool operator<=(const Mod& rhs) const { return x <= rhs.x; }
  constexpr bool operator>=(const Mod& rhs) const { return x >= rhs.x; }
  friend constexpr std::istream& operator>>(std::istream& is, Mod& a) { long long i = 0; is >> i; a = i; return is; }
  friend constexpr std::ostream& operator<<(std::ostream& os, const Mod& a) { return os << a.x; }
public:
  U x;
};

template <typename U>
struct Barrett {
  using UV = std::conditional_t<sizeof(U) <= 4, unsigned long long, unsigned __int128>;
  U m;
  UV im;
  constexpr Barrett(U m_) : m(m_), im((UV)(-1) / m_ + 1) {}
  constexpr U mod() const { return m; }
  constexpr U mul(U a, U b) const {
    UV z = a;
    z *= b;
    constexpr int shift = sizeof(U) * 8;
    UV x = (UV)(((unsigned __int128)(z) * im) >> shift);
    U v = (U)(z - x * m);
    if (m <= v) v += m;
    return v;
  }
};

template <typename U, unsigned int Id = 0>
struct DynMod {
  static_assert(std::is_unsigned_v<U>, "DynMod type should be unsigned");
  using UV = std::conditional_t<sizeof(U) <= 4, unsigned long long, unsigned __int128>;
  using SV = std::conditional_t<sizeof(U) <= 4, long long, __int128>;
  constexpr DynMod() : x(0) {}
  template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
  constexpr DynMod(T y) {
    if constexpr (std::is_signed_v<T>) {
      using S = std::make_signed_t<U>;
      S v = y % S(mod());
      if (v < 0) v += mod();
      x = v;
    } else {
      x = U(y % mod());
    }
  }
  constexpr static void setMod(U m) { bt = Barrett<U>(m); }
  static U mod() { return bt.mod(); }
  // uses invGCD, for coprime mod. if p is prime, fermat's little theorem works a^(mod-2)
  constexpr DynMod inv() const { auto v = invGcd((SV)x, (SV)mod()); assert(v.first == 1); return v.second; }
  constexpr explicit operator U() const { return x; }
  constexpr DynMod operator-() const { return DynMod() -= *this; }
  constexpr DynMod operator+(const DynMod& rhs) const { return DynMod(*this) += rhs; }
  constexpr DynMod operator-(const DynMod& rhs) const { return DynMod(*this) -= rhs; }
  constexpr DynMod operator*(const DynMod& rhs) const { return DynMod(*this) *= rhs; }
  constexpr DynMod operator/(const DynMod& rhs) const { return DynMod(*this) /= rhs; }
  constexpr DynMod& operator+=(const DynMod& rhs) { return (x += rhs.x) >= mod() ? x -= mod() : x, *this; }
  constexpr DynMod& operator-=(const DynMod& rhs) { return (x -= rhs.x) >= mod() ? x += mod() : x, *this; }
  constexpr DynMod& operator*=(const DynMod& rhs) { return x = (UV)x * rhs.x % mod(), *this; }
  constexpr DynMod& operator/=(const DynMod& rhs) { return *this *= rhs.inv(); }
  constexpr bool operator<(const DynMod& rhs) const { return x < rhs.x; }
  constexpr bool operator>(const DynMod& rhs) const { return x > rhs.x; }
  constexpr bool operator==(const DynMod& rhs) const { return x == rhs.x; }
  constexpr bool operator!=(const DynMod& rhs) const { return x != rhs.x; }
  constexpr bool operator<=(const DynMod& rhs) const { return x <= rhs.x; }
  constexpr bool operator>=(const DynMod& rhs) const { return x >= rhs.x; }
  friend constexpr std::istream& operator>>(std::istream& is, DynMod& a) { long long i = 0; is >> i; a = i; return is; }
  friend constexpr std::ostream& operator<<(std::ostream& os, const DynMod& a) { return os << a.x; }
public:
  U x;
  static Barrett<U> bt;
};

const int MOD = 1000000007;
using Mint = Mod<unsigned int, MOD>;

template<typename U, unsigned int Id> Barrett<U> DynMod<U, Id>::bt = MOD;
using DMint = DynMod<unsigned int, 0>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, l, r;
  std::cin >> n >> l >> r;

	int r0=r/3-(l-1)/3;
	int r1=(r+2)/3-(l+1)/3;
	int r2=(r+1)/3-l/3;
  Mint c0 = r0, c1 = r1, c2 = r2;
  for (int i = 1; i < n; ++i) {
    Mint a = (c0 * r0) + (c1 * r2) + (c2 * r1);
    Mint b = (c0 * r1) + (c1 * r0) + (c2 * r2);
    Mint c = (c0 * r2) + (c1 * r1) + (c2 * r0);
    c0 = a, c1 = b, c2 = c;
  }

  std::cout << c0 << "\n";

  return 0;
}
