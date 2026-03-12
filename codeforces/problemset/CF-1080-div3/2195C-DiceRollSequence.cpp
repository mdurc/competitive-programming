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

void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  // dp[i][v]: 0..i ending in v
  const int inf = 1e9;
  std::vector dp(n+1, std::vector<int>(7, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      dp[i][j] = inf;
      for (int k = 1; k <= 6; ++k) {
        if (k == 7-j || k == j) continue;
        if (dp[i-1][k] == inf) continue;
        dp[i][j] = std::min(dp[i][j], dp[i-1][k] + (a[i-1]!=j?1:0));
      }
    }
  }
  std::cout << *std::min_element(dp[n].begin()+1, dp[n].end()) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
