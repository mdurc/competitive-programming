#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> a,b;
        for(int i=0;i<s.size();++i){
            ++a[s[i]];
            ++b[t[i]];
        }

        unordered_map<char,int>::iterator i;
        for(i=a.begin(); i!=a.end(); ++i){
            if (b[i->first] != i->second) return false;
        }
        return true;
    }
};
