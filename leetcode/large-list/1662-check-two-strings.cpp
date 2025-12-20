
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        a=b="";
        int z=word1.size();
        for(int i=0;i<z;++i){
            a+=word1[i];
        }
        z=word2.size();
        for(int i=0;i<z;++i){
            b+=word2[i];
        }
        return a==b;
    }
};
