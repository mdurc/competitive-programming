class Solution {
public:
    /*
    Subproblems: dp[i] is the number of ways to reach step i
    Recurrence:
        - two cases to arrive on step i: either 1 step to i, or 2 steps
        : dp[i] = dp[i-1] + dp[i-2]
    Time: O(n)
    */
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp[n+1];
        dp[0] = 1; dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};