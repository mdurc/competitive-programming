#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // same algorithm as leetcode 26
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        int z=nums.size();
        for(int i=0;i<z;++i){
            if(nums[i]!=val){
                nums[j]=nums[i];
                ++j;
            }
        }
        return j;
    }
};
