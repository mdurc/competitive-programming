class Solution {
public:
    bool neighbor(int r, int c, int row, int col) {
        // No diagonal movement
        if ((row == -1 || col == -1) || (row == r + 1 && col == c) ||
            (row == r - 1 && col == c) || (row == r && col == c + 1) ||
            (row == r && col == c - 1)) {
            return true;
        }
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word, int startr=-1,
               int startc=-1) {
        if (word.size() == 0) return true;

        for (unsigned int r = 0; r < board.size(); ++r) {
            for (unsigned int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] != word[0] || !neighbor(r,c,startr,startc) )
                    continue;

                char temp = board[r][c];
                board[r][c] = '.';
                if (exist(board, word.substr(1), r, c)){
                    return true;
                } else {
                    board[r][c] = temp;
                }
            }
        }
        return false;
    }
};
