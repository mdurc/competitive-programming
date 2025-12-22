#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> days = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"};

  string start_day;
  cin >> start_day;

  int time;
  cin >> time;

  time += 1200;

  if (time >= 2400) {
    time -= 2400;
    if (start_day == "Saturday") {
      start_day = "Sunday";
    } else {
      start_day = *(++find(days.begin(), days.end(), start_day));
    }
  }

  cout << start_day << " ";
  if (time < 100) {
    cout << "00";
  } else if (time < 1000) {
    cout << "0";
  }
  cout << time << "\n";

  return 0;
}
