#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(const string& str){
        map<char,int> m;
        int z=str.size();
        for(int i=0;i<z;++i){
            ++m[str[i]];
        }
        return m.begin()->second;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ret;
        vector<int> store;
        for(const string& W: words){
            store.push_back(f(W));
        }
        sort(store.begin(), store.end(), greater<int>());
        for(const string& Q: queries){
            int q = f(Q), z = store.size();
            int i=0;
            for(;i<z && q<store[i];++i);
            ret.push_back(i);
        }
        return ret;
    }
};
