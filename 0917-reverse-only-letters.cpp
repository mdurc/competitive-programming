#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        // two pointer solution
        // only swap alpha characters
        int z=s.size();
        int i=0,j=z-1;
        while(i<j){
            for(; i<z && !std::isalpha(s[i]) ; ++i);
            for(; j>=0 && !std::isalpha(s[j]) ; --j);
            
            //swap
            if(i<j) std::swap(s[i],s[j]);
            ++i,--j;
        }
        return s;
    }
};

// WITH STACK AND MAP
string reverseOnlyLetters(const string& s) {
    //index and the non-alpha char
    unordered_map<int,char> m;
    stack<char> mystack;
    int z=s.size();
    for(int i=0;i<z;++i){
        if(!std::isalpha(s[i])){
            m[i]=s[i];
        }else{
            mystack.push(s[i]);
        }
    }

    string ret="";
    unordered_map<int,char>::iterator itr;
    for(int i=0 ; i<z ; ++i){
        itr=m.find(i);
        if(itr!=m.end()){
            ret.push_back(itr->second);
        }else{
            ret.push_back(mystack.top());
            mystack.pop();
        }
    }
    return ret;
}
