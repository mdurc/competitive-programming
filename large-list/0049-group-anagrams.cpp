#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        // <sorted, strings>
        unordered_map<string,vector<string>> m;
        int z=strs.size();
        for(int i=0;i<z;++i){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        unordered_map<string,vector<string>>::iterator i=m.begin();
        for(;i!=m.end();++i){
            ret.push_back(i->second);
        }
        return ret;
    }
};
