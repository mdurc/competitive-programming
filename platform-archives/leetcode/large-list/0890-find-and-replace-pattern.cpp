#include <bits/stdc++.h>
using namespace std;


typedef unordered_map<char,char> map_type;
class Solution {
public:
    bool matches(const string& w, const string& p){
        // make sure that no two chars map to the same letter in the pattern
        map_type c_to_p, p_to_c;
        int z=w.size();
        for(int i=0;i<z;++i){
            pair<map_type::iterator,bool> check;
            // check in both directions
            check = c_to_p.insert({w[i],p[i]});
            if(!check.second && check.first->second!=p[i]) return false;

            check = p_to_c.insert({p[i],w[i]});
            if(!check.second && check.first->second!=w[i]) return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string> ret;
       for(const string& w: words){
           if(matches(w,pattern)){
               ret.push_back(w);
           }
       }
       return ret;
    }
};
