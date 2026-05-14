#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int mxo = -1, mno = 2e9;
  int mxe = -1, mne = 2e9;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) {
      mxo = std::max(mxo, a[i]);
      mno = std::min(mno, a[i]);
    } else {
      mxe = std::max(mxe, a[i]);
      mne = std::min(mne, a[i]);
    }
  }

  if (std::is_sorted(a.begin(), a.end())) {
    std::cout << "YES\n";
    return;
  }

  if (mxo == -1 || mxe == -1) {
    std::cout << "NO\n";
    return;
  }

  int ea = n, eb = -1;
  int oa = n, ob = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      if (a[i] > mxo) ea = std::min(ea, i);
      if (a[i] < mno) eb = std::max(eb, i);
    } else {
      if (a[i] > mxe) oa = std::min(oa, i);
      if (a[i] < mne) ob = std::max(ob, i);
    }
  }
  if (ea < eb || oa < ob) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
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
