
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(const string& s, const string& t) {
        // seems like a stack type of problem
        stack<char> s1,s2;
        int z=s.size();
        for(int i=0;i<z;++i){
            if(s[i]=='#'){
                if(!s1.empty()){ s1.pop(); }
            }else{
                s1.push(s[i]);
            }
        }
        z=t.size();
        for(int i=0;i<z;++i){
            if(t[i]=='#'){
                if(!s2.empty()){ s2.pop(); }
            }else{
                s2.push(t[i]);
            }
        }
        return s1==s2;
    }
};
