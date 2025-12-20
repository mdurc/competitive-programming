// https://leetcode.com/problems/split-array-largest-sum/description/
class Solution {
public:
    bool valid(vector<int>& nums, int mx, int k) {
        if (*max_element(nums.begin(),nums.end()) > mx) return false;
        int curr = 0;
        for (int n : nums) {
            if (curr + n > mx) {
                curr = 0;
                --k;
            }
            curr += n;
        }
        return k > 0;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0, r = sum;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(nums, mid, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
