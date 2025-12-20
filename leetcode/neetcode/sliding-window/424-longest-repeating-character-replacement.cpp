class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int max_val = 0;
        unordered_map<char,int> m;
        while (j < s.size()){
            ++m[s[j]];
            max_val = max(max_val, m[s[j]]); // update the max as we go
            while ((j-i+1)-max_val > k){
                --m[s[i]];
                ++i;
            }
            ans = max(ans, j-i+1);
            ++j;
        }
        return ans;
    }
};
