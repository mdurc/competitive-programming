class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_set<char> letters;
        while (j<s.size()){
            while (letters.find(s[j]) != letters.end()){
                letters.erase(s[i]);
                ++i;
            }
            letters.insert(s[j]);
            ans = max(ans, j-i+1);
            ++j;
        }
        return ans;
    }
};
