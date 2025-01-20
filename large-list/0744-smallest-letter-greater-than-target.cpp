#include <iostream>
#include <vector>

class Solution {
public:
    Solution(){
        std::cout<<nextGreatestLetter({'c','f','j'}, 'a')<<std::endl;
        std::cout<<nextGreatestLetter({{'c','f','j'}}, 'c')<<std::endl;
        std::cout<<nextGreatestLetter({'x','x','y','y'}, 'z')<<std::endl;
    }
    char nextGreatestLetter(std::vector<char> letters, char target) {
        int low{}, high{int(letters.size())-1}, mid{};

        while(low<=high){
            mid = low + (high-low)/2;

            if (target >= letters[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return letters[low%letters.size()];
    }
};

int main() { Solution(); }


