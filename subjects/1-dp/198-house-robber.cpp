class Solution {
public:
    /*
    Subproblems: dp[i] is the maximum profit gained within the range [0..i]
    Recurrence:
        - Either: 
            1. don't rob this house, and carry over the last maximum profit from the last house
            2. rob this house and add to the profit that was accumulated from the last robable house
        - dp[i] = max(dp[i-2] + nums[i], dp[i-1])
    Time: O(n)
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for (int i=1; i<n; ++i) {
            int last_house_price = i == 1 ? 0 : dp[i-2];
            dp[i] = max(last_house_price+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};