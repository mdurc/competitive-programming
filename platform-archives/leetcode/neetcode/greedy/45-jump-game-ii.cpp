class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, res = 0;
        while (r < n-1) {
            int dist = 0;
            for (int i = l; i <= r; ++i) {
                dist = max(dist, i+nums[i]);
            }
            l = r+1;
            r = dist;
            ++res;
        }
        return res;
    }
};

/*
// slow but maybe intuitive n^2 solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pred(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n && j <= i+nums[i]; ++j) {
                pred[j].push_back(i);
            }
        }
        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = 10001;
            for (int j: pred[i]) {
                dp[i] = min(dp[i], dp[j]);
            }
            dp[i] += 1;
        }
        return dp[n-1];
    }
};
*/
