class Solution {
    vector<vector<int>> res;
public:
    void solve(vector<int>& a, int target, vector<int> cur = {}, int cur_sum = 0, int idx = 0) {
        if (cur_sum == target) {
            res.push_back(cur);
            return;
        }
        int n = a.size();
        for (int i = idx; i < n; ++i) {
            if (i > idx && a[i] == a[i-1]) continue;
            if (cur_sum + a[i] > target) break;
            cur.push_back(a[i]);
            solve(a, target, cur, cur_sum + a[i], i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates, target);
        return res;
    }
};
