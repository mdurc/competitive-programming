#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    Solution() {
        std::vector< std::string> squares = {"a1", "a2", "a3", "a4", "a5"};
        for (std::string square : squares){
            if (squareIsWhite(square)){
                std::cout<<square<<", is white"<<std::endl;
            }else{
                std::cout<<square<<", is black"<<std::endl;
            }
        }

    }
    bool squareIsWhite(std::string coordinates) {
        //a,b,c == 1,2,3
        // if coordinate is a1, then 11 so -> 1+1 = 2
        // if sum is even, square is black: return false
        // if sum is odd, square is black: return true
        return (coordinates[1] - '0'+ coordinates[0] - 'a' + 1)%2!=0;
    }
};

int main() {
    Solution();
    return 0;
}
