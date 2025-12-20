// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
class Solution {
public:
    bool valid(vector<int>& nums, int k, int dist) {
        // at least k pairs <= dist
        int cnt = 0, n = nums.size();
        int l = 0, r = 0;
        while (l < n || r < n) {
            while (r < n && nums[r] - nums[l] <= dist) {
                ++r;
            }
            cnt += r - l - 1;
            ++l;
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n-1] - nums[0];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(nums, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
