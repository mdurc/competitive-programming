#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // same idea as leetcode 26 and 27
    void moveZeroes(vector<int>& nums) {
        int z=nums.size();
        int j=0;
        for(int i=0;i<z;++i){
            if(nums[i]!=0){
                nums[j]=nums[i];
                ++j;
            }
        }
        for(;j<z;++j){
            nums[j]=0;
        }
    }
};


/* with iterators
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator itr = nums.begin();
        vector<int>::iterator itr2 = nums.begin();
        for(;itr!=nums.end();++itr){
            if(*itr!=0){
                *itr2=*itr;
                ++itr2;
            }
        }
        for(;itr2!=nums.end();++itr2){
            *itr2 = 0;
        }
    }
*/
