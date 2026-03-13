class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        // pair is not hashable
        map<pair<int,int>,unordered_set<char>> grid;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if (board[i][j] == '.') continue;

                if (rows[i].find(board[i][j]) != rows[i].end() ||
                    cols[j].find(board[i][j]) != cols[j].end()) return false;

                pair<int,int> p = {(int)i/3, (int)j/3};
                if(grid[p].find(board[i][j]) != grid[p].end()) return false;

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                grid[p].insert(board[i][j]);
            }
        }
        return true;
    }
};
