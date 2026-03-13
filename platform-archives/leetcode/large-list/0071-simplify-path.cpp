#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string item;
        stack<string> s;
        // convert path to a string stream, and split it by the delimiter '/'.
        stringstream ss(path);
        while(getline(ss, item, '/')){
            if(item==".."){
                if(!s.empty()){
                    s.pop();
                }
            }else if(item!="." && item!=""){
                s.push(item);
            }
        }
        if(s.empty()){
            return "/";
        }
        string result = "";
        // now let's concatenate all valid items.
        while(!s.empty()){
            result = "/" + s.top() + result;
            s.pop();
        }
        return result;
    }
};
