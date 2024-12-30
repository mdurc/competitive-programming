class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m1, m2;
        for (int i=0; i<t.size(); ++i) {
            ++m1[t[i]];
        }

        int have = 0, need = m1.size(); // track unique characters
        pair<int, int> res = {-1, -1}; // for returning the substring
        int ans_len = INT_MAX;
        int i = 0;
        int j = 0;

        while (j < s.size()) {
            ++m2[s[j]];

            if (m1.count(s[j]) && m2[s[j]] == m1[s[j]]) {
                ++have;
            }

            while (have == need) {
                if ((j-i+1) < ans_len) {
                    ans_len = j-i+1;
                    res = {i, j};
                }

                --m2[s[i]];
                if (m1.count(s[i]) && m2[s[i]] < m1[s[i]]) {
                    --have;
                }
                ++i;
            }
            ++j;
        }

        return ans_len == INT_MAX ? "" : s.substr(res.first, ans_len);
    }
};
