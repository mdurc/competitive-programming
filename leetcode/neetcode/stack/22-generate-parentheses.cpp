class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s;
        backtrack(0,0,n,ret,s);
        return ret;
    }

    // must be size of n*2, with n open parentheses, and n close parentheses
    // must start with open parenthesis
    // can only add a closed parthensis when there are more open parenthesis present
    // only add open parenthesis when there are less than n present
    void backtrack(int opens, int closed, int n, vector<string>& ans, string& s) {
        if (opens == closed && opens == n){
            ans.push_back(s);
            return;
        }
        if (opens < n){
            s.append("(");
            backtrack(opens+1, closed, n, ans, s);
            s.pop_back();
        }
        if (closed < opens){
            s.append(")");
            backtrack(opens, closed+1, n, ans, s);
            s.pop_back();
        }
    }
};
