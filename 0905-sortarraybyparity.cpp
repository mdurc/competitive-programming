#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a%2==0 && b%2!=0;
}
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};
