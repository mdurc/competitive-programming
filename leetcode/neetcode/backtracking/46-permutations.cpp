class Solution {
    vector<vector<int>> res;
public:
    void solve(vector<int>& nums, vector<int> cur, int mask) {
        int n = nums.size();
        if (mask == (1 << n) - 1) { // cur.size() == n
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                cur.push_back(nums[i]);
                solve(nums, cur, mask | (1 << i));
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, {}, 0);
        return res;
    }
};
