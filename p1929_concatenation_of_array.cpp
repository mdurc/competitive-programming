#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int z=nums.size();
        vector<int> ret(z*2);
        int i=0;
        for(;i<z;++i){
            ret.push_back(nums[i]);
        }
        for(i=0;i<z;++i){
            ret.push_back(nums[i]);
        }
        return ret;
    }
};


// I believe it is slower, but a shorter solution: ->
/*
int z=nums.size();
vector<int> ret(nums);
int i=0;
for(;i<z;++i){
    ret.push_back(nums[i]);
}
return ret;
*/
