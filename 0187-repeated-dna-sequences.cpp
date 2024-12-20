#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        //sliding window. 10 characters per sequence
        unordered_map<string,int> m;
        int high=9;
        int z=s.size();
        while(high<z){
            ++m[s.substr(high-9,10)];
            ++high;
        }
        unordered_map<string,int>::iterator itr=m.begin();
        for(;itr!=m.end();++itr){
            if(itr->second>1){
                ret.push_back(itr->first);
            }
        }
        return ret;
    }
};
