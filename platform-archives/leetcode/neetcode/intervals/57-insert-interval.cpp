class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = (int)intervals.size();
      std::vector<std::vector<int>> res;
      int i = 0;
      while (i < n && newInterval[0] > intervals[i][1]) {
        res.push_back(intervals[i]);
        i++;
      }
      while (i < n && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        i++;
      }
      res.push_back(newInterval);
      while (i < n) {
        res.push_back(intervals[i]);
        i++;
      }
      return res;
    }
};
