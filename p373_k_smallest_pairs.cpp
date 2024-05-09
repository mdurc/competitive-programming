#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        return (a.first+a.second)<(b.first+b.second);
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int z1=nums1.size(),z2=nums2.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> p;
        for(int i=0;i<z1;++i){
            for(int j=0;j<z2;++j){
                int sum=nums1[i]+nums2[j];
                pair<int,int> curr={nums1[i],nums2[j]};
                if(p.size()<k){
                    p.push(curr);
                }else if((p.top().first+p.top().second)>sum){
                    p.pop();
                    p.push(curr);
                }else{ break; }
            }
        }
        vector<vector<int>> ret;
        while(!p.empty()){
            ret.push_back({p.top().first,p.top().second});
            p.pop();
        }
        return ret;
    }
};
