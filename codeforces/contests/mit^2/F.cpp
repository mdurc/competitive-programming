#include <bits/stdc++.h>
using namespace std;
typedef pair<int,char> pc;

// char m[3] = {'M', 'I', 'T'};
// string solve(int amt[3], string curr = "") {
//   if (amt[0] + amt[1] + amt[2] == 0) return curr;
//   int n = curr.size();
//   for (int i = 0; i < 3; ++i) {
//     if (amt[i] == 0) continue;
//     if ((n >= 2 &&
//           ((curr[n - 2] == 'M' && curr[n - 1] == 'I' && m[i] == 'T') ||
//            (curr[n - 2] == 'T' && curr[n - 1] == 'I' && m[i] == 'M')))) {
//       continue;
//     }
//     if (n == 0 || (n >= 1 && curr[n - 1] != m[i])) {
//       amt[i]--;
//       string res = solve(amt, curr + m[i]);
//       if (!res.empty()) return res;
//       amt[i]++;
//     }
//   }
//   return "";
// }

bool valid(string& s, char c) {
  int n = s.size();
  if (n == 0) return true;
  if (n > 0 && s[n-1] == c) return false;
  if (n >= 2 && ((s[n-2]=='M' && s[n-1]=='I' && c == 'T') ||
                 (s[n-2]=='T' && s[n-1]=='I' && c == 'M'))) return false;
  return true;
}

string solve(int x, int y, int z) {
  vector<pc> counts = {{x, 'M'}, {y, 'I'}, {z, 'T'}};
  string res = "";
  while (true) {
    sort(counts.rbegin(), counts.rend());
    bool ok = false;
    for (auto& [cnt, c] : counts) {
      if (cnt > 0 && valid(res, c)) {
        res += c;
        cnt--;
        ok = true;
        break;
      }
    }
    if (!ok) break;
  }
  if (res.size() == x + y + z) return res;
  return "";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    // int amt[3] = {x, y, z};
    string res = solve(x, y, z);
    if (res.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << res << "\n";
    }
  }

  return 0;
}
