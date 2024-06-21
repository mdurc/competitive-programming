#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ascii of a char is `int(char)`
    int scoreOfString(string s) {
        int ret = 0;
        int z=s.size();
        for(int i=0;i<z-1;++i){
            ret+=abs(int(s[i])-int(s[i+1]));
        }
        return ret;
    }
};
