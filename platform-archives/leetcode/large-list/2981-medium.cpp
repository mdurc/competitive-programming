
#include </usr/local/include/bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> m;
        int max=-1;
        int z=s.size();
        for(int i=0;i<z;++i){
            for(int j=i+1;j<=z;++j){
                int size=j-i;
                if(size<max){continue;}

                int k=1;
                string t=s.substr(i,size);
                for(;k<size;++k){
                    if(t[k]!=t[0]){break;}
                }
                if(k!=size){break;}
                if(++m[t]==3){max=size;}
            }
        }
        return max;
    }
};
