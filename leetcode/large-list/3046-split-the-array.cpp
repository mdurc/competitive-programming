

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> m;
        int z=nums.size();
        for(int i=0;i<z;++i){
            // if the frequency is over 2, return false
            if(++m[nums[i]] > 2){ return 0; }
        }
        return 1;
    }
};


/*
   // for uneven length:
    unordered_map<int,int> m;
    int len_a=0,len_b=0;
    int z=nums.size();
    for(int i=0;i<z;++i){
        // if the frequency is over 2, return false. add first to a, then b, etc.
        if(++m[nums[i]] > 2){ return 0; }
        else if(i%2 == 0){ ++len_a; }
        else{ ++len_b; }
    }
    //cout << len_a << ' ' << len_b << ' ' << z/2 << endl;
    return (len_a == len_b) && (len_a == z/2);
*/
