#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, found = 0;
        int z=nums.size();
        for(int i=0;i<z;++i){
            if(nums[i]%2==0 && nums[i]%3==0){
                sum+=nums[i];
                ++found;
            }
        }
        return !found?0:sum/found;
    }
};
