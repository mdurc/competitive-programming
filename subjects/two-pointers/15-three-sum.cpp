class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // perform 2-sum sorted

        vector<vector<int>> ans;
        for (int i=0; i<nums.size(); ++i){
            // dont reuse same starting value
            if (i>0 && nums[i] == nums[i-1]) continue;

            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // still search for more solutions, but to avoid
                    // duplicates, move left pointer to first new value
                    while(++j < k && nums[j] == nums[j-1]);
                }else if (sum < 0){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return ans;
    }
};
