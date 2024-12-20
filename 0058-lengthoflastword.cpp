#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        for(;i>=0;--i){
            if(s[i]!=' ')break;
        }
        int length=0;
        while(i>=0 && s[i]!=' '){
            --i;
            ++length;
        }
        return length;
    }
};
