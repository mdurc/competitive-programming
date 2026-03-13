class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0 ; i < nums.size() ; ++i){
            unordered_map<int,int>::iterator itr = m.find(target - nums[i]);
            if (itr != m.end() && i != itr->second) return {i, itr->second};
            else m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
