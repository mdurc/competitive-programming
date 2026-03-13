// O(n) time with O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n: nums) {
            res ^= n;
        }
        return res;
    }
};

// O(n) time with O(n) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_set<int> s;
        for (int n: nums) {
            if (!s.insert(n).second) {
                s.erase(n);
            }
        }
        return *s.begin();
    }
};
