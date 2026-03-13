/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

const int mxn = 1e6+1;
int arr[mxn];
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
      std::fill(arr, arr+mxn, 0);
      int n = (int)intervals.size();
      // make the difference array (all zeros initially)
      for (int i = 0; i < n; ++i) {
        arr[intervals[i].start]++;
        arr[intervals[i].end]--;
      }
      // prefix sum of difference array is total range counts
      int pref = 0, res = 0;
      for (int i = 0; i < mxn; ++i) {
        pref += arr[i];
        res = std::max(res, pref);
      }
      return res;
    }
};
