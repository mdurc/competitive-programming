class Solution {
public:
    /*
    Subproblems: dp[i] indicates if s[0..i] can be segemented with valid words
    Recurrence: dp[i] = for any of 0<=j<=i, s[j..i] in dict && dp[j-1]
        - Base case: dp[-1] will represent the empty string and will always be valid
    Time: There are n subproblems, each taking O(n), thus O(n^2) total
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        bool dp[n];
        for (int i=0; i<n; ++i) {
            dp[i] = false;
            for (int j=0; j<=i; ++j) {
                if (dict.find(s.substr(j, i-j+1))!=dict.end()
                    && (j == 0 || dp[j-1])){
                    dp[i] = true;
                }
            }
        }
        return dp[n-1];
    }
};