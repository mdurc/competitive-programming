#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int z = nums.size();
        for(int i=0;i<z;++i){
            for(int j=i;j<z;++j){
                if((abs(i-j)>=indexDifference) &&
                   (abs(nums[i]-nums[j])>=valueDifference)){
                   return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
