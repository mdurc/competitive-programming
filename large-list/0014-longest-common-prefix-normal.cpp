
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ret="";
        int z=strs.size();
        int wz=strs[0].size();
        for(int c=0;c<wz;++c){
            char curr=strs[0][c];
            int i=0;
            for(;i<z;++i){
                if(c>=strs[i].size()||strs[i][c]!=curr){
                    return strs[0].substr(0,c);
                }
            }
        }
        return strs[0];
    }
};
