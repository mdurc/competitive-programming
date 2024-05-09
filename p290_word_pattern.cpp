#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        int last=0;
        for(const char& c:pattern){
            int space=s.find(' ',last);
            string temp=s.substr(last,space-last);
            last=space+1;
            pair<unordered_map<char,string>::iterator,bool> p1=m1.insert({c,temp});
            pair<unordered_map<string,char>::iterator,bool> p2=m2.insert({temp,c});
            if(!p1.second&&p1.first->second!=temp||
               !p2.second&&p2.first->second!=c){
               return 0;
            }
        }
        // make sure that last is (std::string::npos)+1, by going to the end of the string s.
        // Which will equate to (-1)+1 == 0
        return !last;
    }
};


/* //Vector method, without substrings.
    bool wordPattern(string pattern, string s) {
        map<char,string> map1;
        map<string,char> map2;
        vector<string> v1;
        int len = s.length();
        string s1;
        for(int i=0;i<len;i++){      
            if(s[i]!=' '){s1.push_back(s[i]);}
            else{
                v1.push_back(s1);
                s1.clear();
            }
        }
        //get the last string
        v1.push_back(s1);
        if(pattern.length()!=v1.size()){ return false; }

        int len_p = pattern.length();
        // 1. create the maps
        for(int i=0;i<len_p;i++){
            map1[pattern[i]] = v1[i];
            map2[v1[i]] = pattern[i];
        }
        // 2. use the maps
        for(int i=0;i<len_p;i++){
            if(map1[pattern[i]]!=v1[i]){ return false; }
            if((map2[v1[i]])!=pattern[i]){ return false; }
        }
        return true;
    }
*/
