#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int,int> m;
        int z=nums.size();
        for(int i=0;i<z;++i){
            ++m[nums[i]];
        }
        unordered_map<int,int>::iterator itr=m.begin();
        for(;itr!=m.end();++itr){
            if(itr->second==1
                &&m.find(itr->first-1)==m.end()
                &&m.find(itr->first+1)==m.end()){
                ret.push_back(itr->first);
            }
        }
        return ret;
    }
};
