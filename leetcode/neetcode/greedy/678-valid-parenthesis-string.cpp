// DP solution:
class Solution {
    int n;
    map<pair<int,int>,bool> memo;
public:
    bool checkValidString(string s) {
        n = s.size();
        return solve(s,0,0);
    }
    bool solve(string s, int idx, int lefts) {
        if (idx == n) return lefts == 0;
        if (lefts < 0) return false;
        pair<int,int> cur = make_pair(idx,lefts);
        if (memo.find(cur) != memo.end()) return memo[cur];
        bool res = 0;
        if (s[idx] == '(') {
            res = solve(s, idx+1, lefts+1);
        } else if (s[idx] == ')') {
            res = solve(s, idx+1, lefts-1);
        } else {
            res =
            solve(s,idx+1,lefts+1) ||
            solve(s,idx+1,lefts-1) ||
            solve(s,idx+1,lefts);
        }
        memo[cur] = res;
        return res;
    }
};

// Greedy O(1) space:
class Solution {
public:
    bool checkValidString(string s) {
        int mnLeft = 0, mxLeft = 0;
        for (char c : s) {
            if (c == '(') {
                mnLeft++;
                mxLeft++;
            } else if (c == ')') {
                mnLeft--;
                mxLeft--;
            } else {
                mnLeft--;
                mxLeft++;
            }
            if (mxLeft < 0) return false;
            mnLeft = max(mnLeft, 0);
        }
        return mnLeft == 0;
    }
};
