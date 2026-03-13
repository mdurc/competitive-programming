// Bit subsets: O(n*2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int len = 1 << n;
        vector<vector<int>> res;
        for (int i = 0; i < len; ++i) {
            vector<int> cur;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    cur.push_back(nums[j]);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};

// Backtracking solution: O(n*2^n)
class Solution {
  vector<vector<int>> res;
public:
    void backtrack(vector<int>& nums, int idx=0, vector<int> curr={}) {
        int n = nums.size();
        if (idx >= n) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(nums, idx + 1, curr);
        curr.pop_back();
        backtrack(nums, idx + 1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums);
        return res;
    }
};

// Prepending, functional programming approach: O(n*2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            int size = res.size();
            for (int i = 0; i < size; ++i) {
                vector<int> subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }

        return res;
    }
};
