#include "./modint.cpp"

struct Comb {
  int n;
  std::vector<Mint> _fac, _invfac, _inv;
  Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
  Comb(int n) : Comb() { init(n); }
  void init(int m) {
    if (m <= n) return;
    _fac.resize(m + 1);
    _invfac.resize(m + 1);
    _inv.resize(m + 1);
    for (int i = n + 1; i <= m; i++) {
      _fac[i] = _fac[i - 1] * i;
    }
    _invfac[m] = _fac[m].inv();
    for (int i = m; i > n; i--) {
      _invfac[i - 1] = _invfac[i] * i;
      _inv[i] = _invfac[i] * _fac[i - 1];
    }
    n = m;
  }
  void _alloc(int m) { if (m > n) init(2*m); }
  Mint fact(int m) { return _alloc(m), _fac[m]; }
  Mint invfact(int m) { return _alloc(m), _invfac[m]; }
  Mint inv(int m) { return _alloc(m), _inv[m]; }
  Mint choose(int a, int b) { return (a < b || b < 0) ? 0 : fact(a) * invfact(b) * invfact(a - b); }
  Mint permute(int a, int b) { return (a < b || b < 0) ? 0 : fact(a) * invfact(a - b); }
} comb;
