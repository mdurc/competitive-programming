#include "./modint.cpp"

template<typename A, typename B> std::ostream& operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename... Args> std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) { os << "("; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ")"; }
template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> std::ostream& operator<<(std::ostream &os, const T_container &v) { os << "{"; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << "}"; }
void debug_out() { std::cout << std::endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { std::cout << " " << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "]", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
  debug("--- TEST 1: Standard Int (10^9 + 7) ---");
  Mint a = MOD_INT - 1;
  Mint b = 2;
  debug("Start:", a, b);                     // Expect 1000000006 2
  debug("Add (overflow wrap):", a + b);      // Expect 1
  debug("Sub (underflow wrap):", b - a);     // Expect 3
  debug("Mult (near overflow):", a * b);     // Expect 1000000005

  Mint neg1(-13);
  Mint negLarge(-1000000008LL);
  Mint veryNeg(LLONG_MIN);
  debug("Negatives:", neg1, negLarge, veryNeg);
  // Expect 1000000006 1000000006 708828003

  debug("--- TEST 2: 64-bit Mod (u128 Logic) ---");
  const ull MOD_LONG = 1000000000000000003ULL;
  using LongMint = Mod<ull, MOD_LONG>;
  LongMint x = 1000000000000000000ULL;
  LongMint y = 1000000000000000000ULL;
  debug("u128 Mult Check:", x * y); // Expect 9

  debug("--- TEST 3: Edge Cases ---");
  Mint zero = 0;
  Mint one = 1;
  debug("2^0:", bpow(Mint(2), 0));           // Expect 1
  debug("0^0:", bpow(zero, 0));              // Expect 1
  debug("0^5:", bpow(zero, 5));              // Expect 0
  debug("2^Large:", bpow(Mint(2), MOD_INT)); // Expect 2

  debug("Inv(1):", one.inv());             // Expect 1
  debug("Inv(-1):", neg1.inv());           // Expect 1000000006
  debug("1/2:", one / 2);                  // Expect 500000004

  debug("--- TEST 4: Tiny Modulo (Mod 2) ---");
  using Binary = Mod<uint, 2>;
  Binary binA = 1;
  Binary binB = 1;
  debug("1+1 (Mod 2):", binA + binB); // Expect 0
  debug("1-1 (Mod 2):", binA - binB); // Expect 0
  debug("-5 (Mod 2):", Binary(-5));   // Expect 1

  debug("--- TEST DynMod ---");

  debug("u128 Mult Check:", x * y); // Expect 9
  using Dmlong = DynMod<ull, 1>;
  Dmlong::setMod(1000000000000000003ULL);
  Dmlong dx = 1000000000000000000ULL;
  Dmlong dy = 1000000000000000000ULL;
  debug(dx * dy);
  Dmlong::setMod(1234);
  debug(dx * dy); // expect 442

  debug("--- Comb ---");
  debug(comb.choose(5,2));
  debug(comb.fact(5));
  debug(comb.inv(5));
  debug(comb.choose(100000,500)); // 115855765
  return 0;
}
