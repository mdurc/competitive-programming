class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      std::sort(intervals.begin(), intervals.end());
      int n = (int)intervals.size();
      std::vector<std::vector<int>> res = {intervals[0]};
      for (int i = 1; i < n; ++i) {
        int sz = (int)res.size();
        if (intervals[i][0] <= res[sz-1][1]) {
          res[sz-1][1] = std::max(res[sz-1][1], intervals[i][1]);
        } else {
          res.push_back(intervals[i]);
        }
      }
      return res;
    }
};
