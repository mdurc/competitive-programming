// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
class Solution {
public:
    bool valid(vector<int>& nums, int thresh, int n) {
        int sum = 0;
        for (int i : nums) {
            sum += ((i + n - 1) / n);
        }
        return sum <= thresh;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = *max_element(nums.begin(), nums.end());
        int l = 1, r = mx;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(nums, threshold, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
