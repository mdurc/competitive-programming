#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int z=intervals.size();
        std::sort(intervals.begin(), intervals.end());
        for(int i=0;i<z;++i){
            if(!ret.empty() && ret.back()[1]>=intervals[i][0]){
                if(ret.back()[1]<intervals[i][1]){
                    ret.back()[1]=intervals[i][1];
                }
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};
