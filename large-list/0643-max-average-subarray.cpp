#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // sliding window. O(n) solution
    double findMaxAverage(vector<int>& nums, int k) {
        double result = INT_MIN;
        double sum = 0.00;
        int low=0,high=0,size=nums.size();
        while(high<size){
            sum+=nums[high];
            if(high-low+1==k){
                if(sum>result){ result=sum; }
                sum-=nums[low];
                ++low;
            }
            ++high;
        }
        return result/k;
    }
};

/*//O(n^2) solution
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max=0;
        int z=nums.size();
        for(int i=0;i<z && i<=z-k;++i){
            double temp=0;
            for(int j=i;j<z && j-i<k;++j){
                temp+=nums[j];
            }
            max=std::max(max,temp/k);
        }
        return max;
    }
};
*/
