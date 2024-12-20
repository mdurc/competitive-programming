#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> p;
        int z=matrix.size();
        for(int i=0;i<z;++i){
            for(int j=0;j<z;++j){
                p.push(matrix[i][j]);
                if(p.size()>k){
                    p.pop();
                }
            }
        }
        return p.top();
    }
};
