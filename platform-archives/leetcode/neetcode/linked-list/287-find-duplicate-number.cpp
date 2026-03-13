class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // find a cycle in the vector,
        // taking advantage of the fact that the values within nums is [1,n]
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // intersection is found at slow ptr now

        int slow_2 = 0;
        do {
            slow = nums[slow];
            slow_2 = nums[slow_2];
        } while (slow != slow_2);

        return slow;
    }
};
