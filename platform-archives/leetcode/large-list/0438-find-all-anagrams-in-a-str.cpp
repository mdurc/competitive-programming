#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        sort(p.begin(),p.end());
        vector<int> ret;
        int sz = s.size();
        int i=0, j=p.size();

        string curr, sorted;
        while(j<sz){
            curr = s.substr(i,j-i); sorted = curr;
            sort(sorted.begin(),sorted.end());

            if(sorted == p){
                while(1){
                    ret.push_back(i);
                    ++j, ++i;
                    if(j>=sz || s[j]!=s[i-1]){
                        break;
                    }
                }
            }else{
                ++j, ++i;
            }
        }
        return ret;
    }
};
