#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> k;
        // '(', ')', '{', '}', '[' and ']'
        for(const char& c:s){
            if(c=='('||c=='{'||c=='['){
                k.push(c);
            }else if(c==')'&&k.top()=='('||
                    c=='}'&&k.top()=='{'||
                    c==']'&&k.top()=='['){
                k.pop();
            }else{
                return 0;
            }
        }
        return 1;
    }
};
