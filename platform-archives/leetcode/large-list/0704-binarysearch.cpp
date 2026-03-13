#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size();
        int mid;
        while(low!=high){
            mid=low+(high-low)/2;
            if(target==nums[mid]){
                return mid;
            }else if(target>nums[mid]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return -1;
    }
};


/*
// recursive solution
class Solution {
public:
    bool search(vector<int>& nums, int low, int high, int target, int& index){
        // this is better than mid=(high+low)/2 because the latter might overflow when high and low are very large integers.
        // caution: if low = high - 1, then mid = low. and this could lead to an infinite loop situation. and because of this, we should never search the range [mid, high], because that actually means search the range of [low, high], which is a repeat of the existing call.
        int mid = low + (high-low)/2;
        if(low>=high){
            index = low;
            return (target == nums[low]);
        }
        // general case
        if(target<=nums[mid]){
            return search(nums, low, mid, target, index);
        }else{
            return search(nums, mid+1, high, target, index);
        }
    }
    // the driver function
    int search(vector<int>& nums, int target) {
        int index;
        int size = nums.size();
        if(search(nums, 0, size-1, target, index) == true){
            return index;
        }else{
            return -1;
        }
    }
};
*/
