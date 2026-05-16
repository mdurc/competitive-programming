#include <bits/stdc++.h>

void rem(std::vector<int> k) {
  std::cout << "- " << k.size() << " ";
  for (int i: k) std::cout << i << " ";
  std::cout << std::endl;
}

void ans(int i) {
  std::cout << "! " << i << std::endl;
}

int diff(std::unordered_map<int,int>& m1, std::vector<int>& a) {
  std::unordered_map<int,int> m2;
  for (int i: a) m2[i]++;
  for (int i: a) {
    if (m2[i] > m1[i]) {
      return i;
    }
  }
  return -1;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::unordered_map<int,int> m;
  for (int i: a) m[i]++;

  rem({});
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int x = diff(m, a);
  if (x == -1) {
    rem({});
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    x = diff(m, a);
  }

  if (m[x] == 0) {
    for (int i = 0; i < n; ++i) {
      if (a[i] == x) ans(i+1);
    }
    return;
  }

  std::vector<int> r;
  for (int i = 0; i < n; ++i) {
    if (a[i] != x) {
      r.push_back(i+1);
    }
  }

  int res = -1;
  int k = n-r.size();

  rem(r);
  std::vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    std::cin >> b[i];
    if (b[i] != x) res = i;
  }

  if (res == -1) {
    rem({});
    for (int i = 0; i < k; ++i) {
      std::cin >> b[i];
      if (b[i] != x) res = i;
    }
  }
  ans(res+1);
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
