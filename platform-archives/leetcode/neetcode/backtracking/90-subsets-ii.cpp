class Solution {
    vector<vector<int>> res;
public:
    void solve(vector<int>& nums, vector<int> cur, int idx) {
        res.push_back(cur);
        int n = nums.size();
        for (int i = idx; i < n; ++i) {
            if (i != idx && nums[i] == nums[i-1]) {
                // after including the idx, when we exclude any pos, we shouldn't include any duplicates
                continue;
            }
            cur.push_back(nums[i]);
            solve(nums, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums, {}, 0);
        return res;
    }
};
