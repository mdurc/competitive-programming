#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int z=s.size();
        int max=0;
        int i=0,j=0, curr=0;
        unordered_set<char> m;
        while(i<z){
            if(j<z && m.insert(s[j]).second){
                max=std::max(++curr,max);
                ++j;
            }else{
                j=++i;
                curr=0;
                m.clear();
            }
        }
        return max;
    }
};

int main(){
    cout << "abcabcbb" << endl;
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}

