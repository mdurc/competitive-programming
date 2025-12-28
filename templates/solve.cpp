#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using u128 = unsigned __int128;
using i128 = __int128;
using pi = std::pair<int, int>;

#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

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

void solve(){
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
