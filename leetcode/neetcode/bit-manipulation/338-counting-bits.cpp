/*
    0:      0        : dp[0] = 0
    1:      1        : dp[1] = dp[0 >> 1 = 0] + 1   = 1
    2:      10       : dp[2] = dp[2 >> 1 = 1] + 0   = 1
    3:      11       : dp[3] = dp[3 >> 1 = 1] + 1   = 2
    4:      100      : dp[4] = dp[4 >> 1 = 2] + 0   = 1
    5:      101      : dp[5] = dp[5 >> 1 = 2] + 1   = 2
    6:      110      : dp[6] = dp[6 >> 1 = 3] + 0   = 2
    7:      111      : dp[7] = dp[7 >> 1 = 3] + 1   = 3
    8:      1000     : dp[8] = dp[8 >> 1 = 4] + 0   = 1
    9:      1001     : dp[9] = dp[9 >> 1 = 4] + 1   = 2
    10:     1010     : dp[10] = dp[10 >> 1 = 5] + 0 = 2
    11:     1011     : dp[11] = dp[11 >> 1 = 5] + 1 = 3
    12:     1100     : dp[12] = dp[12 >> 1 = 6] + 0 = 2
    13:     1101     : dp[13] = dp[13 >> 1 = 6] + 1 = 3
    14:     1110     : dp[14] = dp[14 >> 1 = 7] + 0 = 3
    15:     1111     : dp[15] = dp[15 >> 1 = 7] + 1 = 4
    16:     10000    : dp[16] = dp[16 >> 1 = 8] + 0 = 1
*/
// intuitive dp approach
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        // still a bottom up approach, with dp[0] as base case of 0
        // we simply check how many 1s from the version of 'i' without the LSB, then add the LSB
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

/*
    0:      0        : dp[0] = 0
    1:      1        : dp[1] = 1 + dp[1-1]   = 1
    2:      10       : dp[2] = 1 + dp[2-2]   = 1 (new power of two)
    3:      11       : dp[3] = 1 + dp[3-2]   = 2
    4:      100      : dp[4] = 1 + dp[4-4]   = 1 (new power of two)
    5:      101      : dp[5] = 1 + dp[5-4]   = 2
    6:      110      : dp[6] = 1 + dp[6-4]   = 2
    7:      111      : dp[7] = 1 + dp[7-4]   = 3
    8:      1000     : dp[8] = 1 + dp[8-8]   = 1 (new power of two)
    9:      1001     : dp[9] = 1 + dp[9-8]   = 2
    10:     1010     : dp[10] = 1 + dp[10-8] = 2
    11:     1011     : dp[11] = 1 + dp[11-8] = 3
    12:     1100     : dp[12] = 1 + dp[12-8] = 2
    13:     1101     : dp[13] = 1 + dp[13-8] = 3
    14:     1110     : dp[14] = 1 + dp[14-8] = 3
    15:     1111     : dp[15] = 1 + dp[15-8] = 4
    16:     10000    : dp[16] = 1 + dp[16-16] = 1 (new power of two)
*/
// Other dp approach
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        // D(0) = 0
        // D(i) = 1 + D(i - last_pwr_of_two)
        // we can note that the power of 2s are separating groups for the DP relation
        int offset = 1;
        for (int i=1; i <= n; ++i) {
            if (offset * 2 == i) {
                offset = i;
            }
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }
};
