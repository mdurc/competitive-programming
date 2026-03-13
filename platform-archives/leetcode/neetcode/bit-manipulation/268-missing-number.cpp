class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sum up the values from 0 to n, then subtract by the sum of all values in nums
        int sum = (nums.size() + 1) * nums.size() / 2;
        for(int n: nums){
            sum -= n;
        }
        return sum;
    }
};

// Less intuitive solution without solution formula
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // start sum of indices at size
        int sum = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            // without formula, the sum is: size + i0 + i1 + i2 ...
            sum += (i - nums[i]);
        }
        return sum;
    }
};
