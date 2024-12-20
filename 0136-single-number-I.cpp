#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N), O(1) solution with bitwise XOR
    int singleNumber(vector<int>& nums) {
        int one=0;
        int z=nums.size();
        for(int i=0;i<z;++i){
            one^=nums[i];
        }
        return one;
    }
};

// O(NlogN) runtime with Constant Space Solution
int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i+=2) {
        if(nums[i]!=nums[i-1])
            return nums[i-1];
    }
    return nums[nums.size()-1];
}
