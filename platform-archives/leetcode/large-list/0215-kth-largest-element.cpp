#include <vector>
#include <queue>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> p;
        for(int n:nums){
            p.push(n);
        }
        for(;k>1;--k){
            p.pop();
        }
        return p.top();
    }
};
