#include <bits/stdc++.h>

const int inf = 1e9;

int check(int target, int k) {
  if (target == 1) return 0;
  std::vector<int> divs;
  for (int i = 1; i * i <= target; ++i) {
    if (target % i == 0) {
      divs.push_back(i);
      if (i != target/i) divs.push_back(target / i);
    }
  }
  std::sort(divs.begin(), divs.end());
  int n = (int)divs.size();
  std::vector<int> dp(n, inf);
  dp[0] = 0;
  for(int i = 1; i < n; i++){
    for(int j = i - 1; j >= 0; j--){
      if(divs[i] / divs[j] > k){
        break;
      }
      if(divs[i] % divs[j] == 0) {
        dp[i] = std::min(dp[i], dp[j] + 1);
      }
    }
  }
  return dp[n - 1];
}

void solve() {
  int x, y, k;
  std::cin >> x >> y >> k;
  int g = std::gcd(x, y);
  x /= g, y /= g;
  int a = check(x, k), b = check(y, k);
  if (a == inf || b == inf) {
    std::cout << "-1\n";
  } else {
    std::cout << a + b << "\n";
  }
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
