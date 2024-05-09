

#include <map>


#include <iostream>
#include <vector>

class Solution {
public:
    
    Solution() {
        std::vector<int> nums = {3,3};
        std::vector<int> t = twoSum(nums, 6);

        for (int v: t){
            std::cout<<v<<'\n';
        }
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> m;
        for(int i = 0 ; i <nums.size() ; ++i){
            m[nums[i]] = i;
        }
        for(int i = 0 ; i <nums.size() ; ++i){
            if(m.find(target-nums[i])!=m.end() && i!=m[target-nums[i]]){
                return {i, m[target-nums[i]]};
            }
        }
        return {-1, -1};
    }
};

int main() { Solution(); }




