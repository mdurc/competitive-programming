#include <iostream>

#include <vector>
class Solution {
public:
    Solution(){
        std::cout<<searchInsert({1,3,5,6}, 5)<<std::endl;
        std::cout<<searchInsert({1,3,5,6}, 2)<<std::endl;
        std::cout<<searchInsert({1,3,5,6}, 7)<<std::endl;
    }
    int searchInsert(std::vector<int> nums, int target) {
        int low{}, high{int(nums.size())}, mid{};

        while(low!=high){
            mid = low + (high-low)/2;
            if (target == nums[mid]){
                return mid;
            }else if(target > nums[mid]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};

int main() { Solution(); }


