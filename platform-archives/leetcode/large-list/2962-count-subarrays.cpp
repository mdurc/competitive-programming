#include </usr/local/include/bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // sliding window:
        // if the condition is met from [i,j],
        //  then it is also met for all sub arrays from [i,n], where j<n<size
        long long ret=0;
        int max=*max_element(nums.begin(),nums.end()),i=0,j=0,count=0;
        int s=nums.size();
        while(j<s){
            // potentially increment the count
            count+=nums[j]==max;
            while(i<=j&&count>=k){
                ret+=s-j;
                count-=nums[i]==max;
                ++i;
            }
        }
        ++j;
        return ret;
    }
};



/*
slow version:

long long ret = 0;
int s = nums.size();
int max = 0;
for (int i = 0; i < s; ++i) {
    int count = 0;
    for (int j = i; j < s; ++j) {
        if (nums[j] > max) {
            ret = count = 0;
            max = nums[j];
        }
        if (count >= k || (nums[j] == max && ++count == k)) {
            ++ret;
        }
    }
}
return ret;
*/
