class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dist = 0;
        for (int i = 0; i < n; ++i) {
            if (i > dist) return false;
            dist = max(dist, i + nums[i]);
        }
        return true;
    }
};
