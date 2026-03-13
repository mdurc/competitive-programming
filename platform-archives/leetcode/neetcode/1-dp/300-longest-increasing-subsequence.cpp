class Solution {
public:
    /*
    Subproblems: dp[i] is the length of the longest subsequence from nums[0..i]
    Recurrence: dp[i] = max(0<=j<i && nums[j] < nums[i]){dp[j]}
    Time: O(n^2)
    */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int ans = 1;
        for (int i=0; i<n; ++i) {
            dp[i] = 1;
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};