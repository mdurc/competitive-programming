#include <bits/stdc++.h>
using namespace std;

/*
https://medium.com/@jaycchiu524/leetcode-137-single-number-ii-bit-manipulation-solution-explanation-1f0dd647d9ee
When a number appears

the first time: add to once
the second time: remove from once and add to twice
the third time: remove from twice and won’t add to once because of ~twice
*/

class Solution {
public:
    // O(N) time and O(1) space
    int singleNumber(vector<int>& nums) {
        int one=0,two=0;
        int z=nums.size();
        for(int i=0;i<z;++i){
            one=(one^nums[i]) & ~two;
            two=(two^nums[i]) & ~one;
        }
        return one;
    }
};

int singleNumber(vector<int>& nums) {
    // linear runtime
    // NOT CONSTANT extra space
    // Bitwise manipulation is required for constant space
    unordered_map<int,int> m;
    int z=nums.size();
    for(int i=0;i<z;++i){
        ++m[nums[i]];
    }
    unordered_map<int,int>::iterator i=m.begin();
    for(;i!=m.end();++i){
        if(i->second==1){
            return i->first;
        }
    }
    return -1;
}
