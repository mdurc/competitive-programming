class Solution {
    vector<vector<string>> res;
public:
    bool pal(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }
    void solve(string& s, vector<string> cur, int l, int r) {
        int n = s.size();
        if (r >= n) {
            if (l == r) res.push_back(cur);
            return;
        }
        if (pal(s,l,r)) {
            cur.push_back(s.substr(l,r-l+1));
            solve(s,cur,r+1,r+1);
            cur.pop_back();
        }
        solve(s,cur,l,r+1);
    }
    vector<vector<string>> partition(string s) {
        solve(s,{},0,0);
        return res;
    }
};
