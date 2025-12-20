#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> available;
        int z=magazine.size();
        for(int i=0;i<z;++i){
            ++available[magazine[i]];
        }
        z=ransomNote.size();
        for(int i=0;i<z;++i){
            if(--available[ransomNote[i]]<0){
                return false;
            }
        }
        return true;
    }
};
