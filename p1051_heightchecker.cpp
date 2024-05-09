

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    // O(nlogn + n) same
    int heightChecker(vector<int>& heights) {
        // we want a min heap
        priority_queue<int,vector<int>,greater<int>> s;
        int z= heights.size();
        for(int i=0;i<z;++i){
            s.push(heights[i]);
        }
        int ret=0;
        // count the number of differences
        for(int i=0;i<z;++i){
            ret+=s.top()!=heights[i];
            s.pop();
        }
        return ret;
    }

    // include algorithm
    int height(vector<int>& heights){
        int ret=0;
        vector<int> o(heights);
        sort(o.begin(),o.end());
        int z=heights.size();
        for(int i=0;i<z;++i){
            ret+=o[i]!=heights[i];
        }
        return ret;
    }
};
