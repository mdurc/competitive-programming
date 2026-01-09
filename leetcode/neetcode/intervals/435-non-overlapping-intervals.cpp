class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      std::sort(intervals.begin(), intervals.end());
      int res = 0, n = (int)intervals.size();
      int last = intervals[0][1];
      for (int i = 1; i < n; ++i) {
        if (last > intervals[i][0]) {
          res++;
          last = std::min(last, intervals[i][1]);
        } else {
          last = intervals[i][1];
        }
      }
      return res;
    }
};
