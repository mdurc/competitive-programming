#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0, z = s.size();
        for(int i=0;i<z;++i){
            count += s[i]==letter;
        }
        return (count*100)/z;
    }
};
