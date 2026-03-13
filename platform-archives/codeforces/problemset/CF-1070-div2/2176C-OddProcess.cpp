#include <bits/stdc++.h>

using ll = long long;

template<typename A, typename B> std::ostream& operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename... Args> std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) { os << "("; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ")"; }
template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> std::ostream& operator<<(std::ostream &os, const T_container &v) { os << "{"; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << "}"; }
void debug_out() { std::cerr << std::endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { std::cerr << " " << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) std::cerr << "[" << __FUNCTION__ << ":" << __LINE__ << "]", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> evens, odds;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] % 2 == 0) {
      evens.push_back(a[i]);
    } else {
      odds.push_back(a[i]);
    }
  }
  int en = evens.size(), eo = odds.size();
  if (en == n) {
    for (int i = 0; i < n; ++i) {
      std::cout << "0 ";
    }
    std::cout << "\n";
    return;
  }

  sort(evens.rbegin(),evens.rend());
  sort(odds.rbegin(),odds.rend());

  std::vector<ll> ps(en+1);
  ps[0] = 0;
  for (int i = 1; i <= en; ++i) ps[i] = ps[i-1] + evens[i-1];

  int inc_odds = 1, inc_even = 0;
  for (int k = 1; k <= n; ++k) {
    if (k > 1) {
      if (inc_even < en) {
        ++inc_even;
      } else {
        if (inc_odds + 2 <= eo && inc_even > 0) {
          inc_odds += 2;
          inc_even--;
        } else {
          inc_odds++;
        }
      }
    }
    if (inc_odds % 2 == 1) {
      std::cout << odds[0] + ps[inc_even] << " ";
    } else {
      std::cout << "0 ";
    }
  }
  std::cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
