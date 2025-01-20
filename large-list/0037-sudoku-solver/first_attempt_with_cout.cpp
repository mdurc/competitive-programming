#include <array>
#include <iostream>
#include <vector>

class Solution {
    public:
    Solution() {
        std::vector<std::vector<char>> b{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        solveSudoku(b);
        clear();
        if (!is_solved(b)){
            std::cout<<"No solution"<<std::endl;
        }else{
            std::cout << "SOLVED: " << std::endl;
        }
        print_board(b);
    }
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::array<char, 9> vals{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        board = solve(board, vals);
    }

    std::vector<std::vector<char>> solve(std::vector<std::vector<char>> board, std::array<char,9> vals){

        for (int r{}; r < 9; r++) {
            for (int c{}; c < 9; c++) {
                clear();
                std::cout<<"updating\n";
                print_board(board);

                if (board[r][c] == '.') {
                    for (char possible : vals) {
                        if (is_valid_move(r, c, possible, board)) {
                            board[r][c] = possible;
                            std::vector<std::vector<char>> temp {solve(board,vals)};
                            if (is_solved(temp)){
                                return temp;
                            }
                        }else if(possible == '9'){ 
                            //means no values work, so return to the original board.
                            // therefore the first recursive call that assigns the temp vector
                            // will become just the board itself and will not change, and will try
                            // the next possible value at the very very first recursive call.
                            return board;
                        }
                    }
                }
            }
        }
        //This should never arrive.
        // worst case, the first possible solution goes through all possible
        // values up to 9 and it still doesnt solve. Therefore all solutions
        // fail and the return statement above activates and recurses down to 
        // the beginning
        return board; // gone through all but not a solution. return original board
    }
    void clear() {
        // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
        std::cout << "\x1B[2J\x1B[H";
    }

    bool is_valid_move(int r, int c, char num,
                       std::vector<std::vector<char>> board) {
        // Check row and column
        for (int i = 0; i < 9; ++i) {
            if (board[r][i] == num || board[i][c] == num) {
                return false;
            }
        }

        //check 3x3
        int sr{(r / 3) * 3};
        int sc{(c / 3) * 3};
        for (int nr{sr}; nr < sr + 3; nr++) {
            for (int nc{sc}; nc < sc + 3; nc++) {
                if (board[nr][nc] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool is_solved(std::vector<std::vector<char>> board) {
        for (int r{}; r < 9; r++) {
            for (int c{}; c < 9; c++) {
                char temp = board[r][c];
                board[r][c] = '.';
                if (!is_valid_move(r, c, temp, board)) {
                    return false;
                } else {
                    board[r][c] = temp;
                }
            }
        }
        return true;
    }

    void print_board(std::vector<std::vector<char>> board) {
        for (int r{}; r < 9; r++) {
            for (int c{}; c < 9; c++) {
                std::cout << board[r][c] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main() {
    Solution();
    return 0;
}
