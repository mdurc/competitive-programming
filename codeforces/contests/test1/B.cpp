#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int MN = 1e5 + 5;

int n, k;
vector<int> ans;
vector<int> seen(MN, -1);

int query(int x) {
  if (x <= 0 || x > (n - k)) return -1;
  if (seen[x] != -1) return seen[x];
  cout << "? " << x << endl;
  int rep;
  cin >> rep;
  seen[x] = rep;
  return rep;
}

void answer(vector<int>& ans) {
  sort(ans.begin(), ans.end());
  cout << "!";
  for (int i = 0; i < k; ++i) {
    cout << " " << ans[i];
  }
  cout << endl;
  exit(0);
}

int upper(int a) {
  int l = 1, r = (n - k);
  int num = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int val = query(mid);
    if (val == -1 || val > a) {
      r = mid - 1;
    } else {
      num = mid;
      l = mid + 1;
    }
  }
  return num;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 1; i <= k; ++i) {
    int l = 1, r = n;
    int num = n;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if ((mid - upper(mid)) >= i) {
        num = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ans.push_back(num);
  }

  answer(ans);

  return 0;
}
