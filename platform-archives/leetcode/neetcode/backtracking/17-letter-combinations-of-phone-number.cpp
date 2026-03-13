class Solution {
    vector<string> res;
    vector<string> m = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void solve(string& digits, string cur, int idx) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (char c: m[(digits[idx]-'0')-2]) {
            solve(digits,cur+c,idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(digits, "", 0);
        return res;
    }
};
