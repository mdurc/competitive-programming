class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int best = 0;

        // faster way to convert to set instead of: for(){s.insert(..)}
        unordered_set<int> s(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); ++i){
            if(s.find(nums[i]-1) == s.end()){
                int curr = 1;
                while(s.find(nums[i]+curr) != s.end()){
                    ++curr;
                }
                if (curr>best) best = curr;
            }
        }
        return best;
    }
};
