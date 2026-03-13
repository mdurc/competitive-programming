#include <bits/stdc++.h>

template<typename A, typename B> std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename... Args> std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) { os << "("; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ")"; }
template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> std::ostream& operator<<(std::ostream& os, const T_container& v) { os << "{"; std::string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << "}"; }
template<typename T, typename Container> std::ostream& operator<<(std::ostream& os, std::stack<T, Container> s) { os << "{"; while (!s.empty()) { os << s.top() << (s.size() > 1 ? ", " : ""); s.pop(); } return os << "}"; }
template<typename T, typename Container> std::ostream& operator<<(std::ostream& os, std::queue<T, Container> q) { os << "{"; while (!q.empty()) { os << q.front() << (q.size() > 1 ? ", " : ""); q.pop(); } return os << "}"; }
template<typename T, typename Container, typename Compare> std::ostream& operator<<(std::ostream& os, std::priority_queue<T, Container, Compare> pq) { os << "{"; while (!pq.empty()) { os << pq.top() << (pq.size() > 1 ? ", " : ""); pq.pop(); } return os << "}"; }
void debug_out() { std::cout << std::endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { std::cout << " " << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "]", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int mxn = 2e5+5;
int n, mod;
int dp[mxn];
int div_diff[mxn];

void solve() {
  std::cin >> n >> mod;
  dp[1] = 1;
  int sub = 1, div = 0; /* running sums */
  for (int i = 1; i <= n; ++i) {
    if (i > 1) {
      div = (div + div_diff[i]) % mod;
      dp[i] = (sub + div) % mod;
      sub = (sub + dp[i]) % mod;
    }
    for (int j = 2; i * j <= n; ++j) {
      int l = i*j;
      int r = (i+1)*j;
      div_diff[l] = (div_diff[l] + dp[i]) % mod;
      if (r <= n) div_diff[r] = (div_diff[r] - dp[i] + mod) % mod;
    }
  }
  std::cout << dp[n] << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
