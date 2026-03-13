#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int z=nums.size();
        for(int i=0;i!=z;++i){
            unordered_map<int,int>::iterator itr=m.find(nums[i]);
            if(itr!=m.end()&&abs(itr->second-i)<=k){
                return 1;
            }
            m[nums[i]]=i;
        }
        return 0;
    }
};
