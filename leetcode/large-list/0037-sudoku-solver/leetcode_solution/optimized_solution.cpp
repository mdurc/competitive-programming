#include <vector>
#include <array>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::array<char, 9> vals{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        solve(board, vals);
    }

    bool solve(std::vector<std::vector<char>>& board, const std::array<char, 9>& vals) {
        for (int r{}; r<9; r++){
            for (int c{}; c<9; c++){
                if (board[r][c]=='.'){              // Base case if statment
                    for (char possible: vals){
                        if (is_valid_move(r, c, possible, board)){
                            board[r][c]= possible;
                            if (solve(board,vals)){
                                return true;
                            }
                            // When solve returns false the board should reset the
                            // current location that was just attempted.

                            // NOTE: Necessary so that every recursive change
                            //      to 'board' reverts and the board is reset
                            //      to try the next value that is up at the
                            //      beginning
                            board[r][c] = '.';
                        }
                    }

                    // Base case 1. There are no possible options from vals
                    // that lead to a solution. correctly solved.
                    // The if statment was triggered, but there are no values
                    // that lead to a solve.
                    return false;
                }
            }
        }
        // Base case 2.
        // Solution is found because there are no more '.' that trigger the 
        // interior if statement.
        // If there are no more '.', this means that all values were placed
        // as a *is_valid_move*, which means the entire board is solved.
        return true;
    }

    bool is_valid_move(int r, int c, char num, const std::vector<std::vector<char>>& board) {

        //check row and column
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
};

int main(){
    return 0;
}
