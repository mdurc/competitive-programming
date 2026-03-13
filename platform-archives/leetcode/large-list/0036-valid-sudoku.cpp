
#include <vector>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int r{}; r<9;r++){
            for(int c{}; c<9;c++){
                if (board[r][c]!='.' && !validPos(board, r, c, board[r][c])){
                    return false;
                }
            }
        }
        return true;
    }

    bool validPos(std::vector<std::vector<char>>& board, const int& r, const int& c, const char& val){
        for (int i{}; i<9;i++){
            if ((i!=c && board[r][i]==val) || (i!=r && board[i][c]==val)){
                return false;
            }
        }

        int nr{(r/3) * 3};
        int nc{(c/3) * 3};
        std::vector<char> grid{};

        for (int m{nr} ; m<nr+3; m++){
            for (int n{nc}; n< nc+3; n++){
                if(std::find(grid.begin(), grid.end(), board[m][n])!=grid.end()){
                    return false;
                }
                if (board[m][n]!='.'){
                    grid.push_back(board[m][n]);
                }
            }
        }
        return true;
    }
};


int main(){
    return 0;
}
