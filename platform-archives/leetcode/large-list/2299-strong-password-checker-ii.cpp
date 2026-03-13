#include <bits/stdc++.h>
using namespace std;


//It has at least 8 characters.
//It contains at least one lowercase letter.
//It contains at least one uppercase letter.
//It contains at least one digit.
//It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
//It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).

class Solution {
public:
    bool strongPasswordCheckerII(const string& password) {
        int z = password.size();
        if(z<8) return 0;

        bool special=0, upper=0, lower=0, digit=0;

        for(int i=0;i<z;++i){
            const char& ch = password[i];
            if((i+1<z) && (ch == password[i+1])){
                return 0;
            }else if(ch>='a'&&ch<='z') { lower=1; }
            else if(ch>='A'&&ch<='Z') { upper=1; }
            else if(ch>='0'&&ch<='9') { digit=1; }
            else{ special=1; }
        }

        return special && upper && lower && digit;
    }
};
