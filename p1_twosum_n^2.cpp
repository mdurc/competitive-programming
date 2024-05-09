

#include <iostream>
#include <vector>

class Solution {
public:
    
    Solution() {
        std::vector<int> nums{{2,7,11,15}};
        std::vector<int> t{twoSum(nums, 9)};

        for (int v: t){
            std::cout<<v<<'\n';
        }
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i{} ; i<nums.size();i++){
            for (int j{}; j<nums.size();j++){
                if (i!=j && nums[i]+nums[j]==target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() { Solution(); }




