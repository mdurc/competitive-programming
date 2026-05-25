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

struct SuffixArray {
  int n;
  std::vector<int> p, c, lcp;
  SuffixArray(std::string s) {
    s += '$';
    n = (int)s.size();

    int k = std::max(256, n);
    p.assign(n, 0);
    c.assign(n, 0);
    std::vector<int> cnt(k, 0);

    // sort single characters
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < k; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int rank = 1;
    for (int i = 1; i < n; i++) {
      if (s[p[i]] != s[p[i-1]]) rank++;
      c[p[i]] = rank - 1;
    }

    // radix sort for powers of 2
    std::vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
      // Right Half: p is already sorted by the right-half rank.
      // We identify the starting indices of the left-halves by shifting back 2^h.
      for (int i = 0; i < n; i++) {
        pn[i] = (p[i]-(1<<h) + n) % n;
      }

      // Left Half: Stable counting sort on the left-half prefix-ranks
      for (int i = 0; i < rank; i++) cnt[i] = 0;
      for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
      for (int i = 1; i < rank; i++) cnt[i] += cnt[i - 1];

      // insert in reverse order of partially sorted pairs (stable counting sort)
      for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

      // recompute the next equivalence class array (new prefix-ranks)
      cn[p[0]] = 0;
      rank = 1;
      for (int i = 1; i < n; i++) {
        std::pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
        std::pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
        if (cur != prev) ++rank;
        cn[p[i]] = rank - 1;
      }
      c.swap(cn);
    }
    build_lcp(s);

    debug(p, c);
    debug(lcp);
  }

  // Kasai's Algorithm: O(N)
  void build_lcp(const std::string& s) {
    lcp.assign(n, 0);
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
      int pi = c[i]; // rank of suffix i
      int j = p[pi - 1]; // the suffix just before it in the sorted array
      while (s[i + k] == s[j + k]) k++;
      lcp[pi] = k;
      k = std::max(0, k - 1); // LCP of next suffix is at least k - 1
    }
  }
};

int main() {
  SuffixArray sa("abaab");
}
