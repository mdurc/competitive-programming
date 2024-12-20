#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void adjust(const string& str,unordered_set<string>& s){
        int i=0, z=str.size();
        bool local_name=true;
        string temp="";
        for(;i<z;++i){
            if(str[i]=='@'){ local_name=false; }
            if(local_name){
                if(str[i]=='.'){
                    continue;
                }else if(str[i]=='+'){
                    for(;str[i]!='@';++i);
                    local_name=false;
                }
            }
            temp+=str[i];
        }
        s.insert(temp);
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        int z=emails.size();
        for(int i=0;i<z;++i){
            adjust(emails[i],s);
        }
        return s.size();
    }
};
