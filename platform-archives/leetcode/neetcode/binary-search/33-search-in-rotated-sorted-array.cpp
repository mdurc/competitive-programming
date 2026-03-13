class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find minimum element in nums with binary search, then do another
        int i = 0;
        int j = nums.size()-1;
        while (i<j){
            int mid = i + (j-i)/2;
            if (nums[j] > nums[mid]){
                j = mid;
            }else{
                i = mid + 1;
            }
        }
        // i is the pivot location
        j = nums.size()-1;
        if (target < nums[i] || target > nums.back()){
            // check which side of vector we need to search
            j = i;
            i = 0;
        }

        while(i<=j){
            int mid = i + (j-i)/2;
            if (target == nums[mid]){
                return mid;
            }else if (target > nums[mid]){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }

        return -1;
    }
};
