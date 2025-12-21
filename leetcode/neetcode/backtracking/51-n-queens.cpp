// Regular backtracking:
class Solution {
    vector<vector<string>> res;
public:
    bool valid(vector<string>& cur, int r, int c) {
        int n = cur.size();
        for (int i = 0; i < n; ++i) {
            if (cur[i][c] == 'Q')  return false;
            if (cur[r][i] == 'Q')  return false;
        }
        for (int i = 1; i < n; ++i) {
            if (r+i < n && c+i < n && cur[r+i][c+i] == 'Q') return false;
            if (r+i < n && c-i >= 0 && cur[r+i][c-i] == 'Q') return false;
            if (r-i >= 0 && c+i < n && cur[r-i][c+i] == 'Q') return false;
            if (r-i >= 0 && c-i >= 0 && cur[r-i][c-i] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string>& cur, int r) {
        int n = cur.size();
        if (r == n) {
            res.push_back(cur);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (valid(cur, r, c)) {
                cur[r][c] = 'Q';
                solve(cur, r+1);
                cur[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        solve(cur, 0);
        return res;
    }
};

// With bitmask:
class Solution {
    vector<vector<string>> res;
    int col = 0, posDiag = 0, negDiag = 0;
public:
    void solve(vector<string>& cur, int r) {
        int n = cur.size();
        if (r == n) {
            res.push_back(cur);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if ((col & (1 << c)) || (posDiag & (1 << (r + c))) || (negDiag & (1 << (r - c + n)))) {
                continue;
            }
            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
            cur[r][c] = 'Q';
            solve(cur, r+1);
            col ^= (1 << c);
            posDiag ^= (1 << (r + c));
            negDiag ^= (1 << (r - c + n));
            cur[r][c] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        solve(cur, 0);
        return res;
    }
};
