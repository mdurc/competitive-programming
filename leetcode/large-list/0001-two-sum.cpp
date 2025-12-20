#include <unordered_map>
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
        std::unordered_map<int, int> m;
        for (int i = 0 ; i < nums.size() ; ++i){
            std::unordered_map<int,int>::iterator itr = m.find(target - nums[i]);
            if (itr != m.end() && i != itr->second) return {i, itr->second};
            else m[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() { Solution(); }




