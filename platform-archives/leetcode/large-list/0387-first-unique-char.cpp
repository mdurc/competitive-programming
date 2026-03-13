#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int z=s.size();
        unordered_map<char,int> m;
        for(int i=0;i<z;++i){
            ++m[s[i]];
        }
        int index=0;
        for(int i=0;i<z;i++){
            if(m[s[i]]>1){ index++; }
            else{ break; }
        }
        if(index>=z){ return -1; }
        return index;
    }
};
