#include <bits/stdc++.h>

const int mxsum = 10000001;
std::vector<int> factors(mxsum, 0);
void precompute() {
  for (int i = 1; i < mxsum; ++i) {
    for (int j = i; j < mxsum; j += i) {
      ++factors[j];
    }
  }
  factors[0] = 0;
}

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  std::vector<int> ps(n+1, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ps[i+1] = ps[i] + a[i];
  }
  std::vector<int> suffix(n+1, 0);
  suffix[n] = ps[n];
  for (int i = n-1; i >= 0; --i) {
    suffix[i] = std::max(ps[i], suffix[i+1]);
  }

  std::vector<int> sub_sum(n);
  for (int i = 0; i < n; ++i) {
    sub_sum[i] = suffix[i+1] - ps[i];
  }

  // starting index of candidate sums
  std::vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a, int b) { return sub_sum[a] > sub_sum[b]; });
  int ans = -2e9;
  bool found = 0;
  for (int i: idx) {
    if (found && sub_sum[i] <= ans) break;
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += a[j];
      if (!found || cur_sum > ans) {
        if (factors[abs(cur_sum)] <= x) {
          ans = cur_sum;
          found = 1;
        }
      }
    }
  }

  std::cout << (found ? ans: 0) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  precompute();
  solve();

  return 0;
}
