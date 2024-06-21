#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        int z=nums.size();
        for(int i=0;i<z;++i){ s.insert(nums[i]); }
        vector<int> ret;
        for(int i=1;i<=z;++i){
            if(s.find(i)==s.end()){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
