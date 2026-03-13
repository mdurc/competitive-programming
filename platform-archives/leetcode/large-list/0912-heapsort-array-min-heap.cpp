#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int z=nums.size();
        for(int i=0;i<z;++i)
            pq.push(nums[i]);
        vector<int>ret;
        while(!pq.empty()){
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
