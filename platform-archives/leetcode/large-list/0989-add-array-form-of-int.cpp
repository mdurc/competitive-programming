#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int z=num.size(),carry=0;
        vector<int> ret;
        for(int i=z-1 ; i>=0 || k>0 || carry>0 ; --i){
            int digit = (i >= 0) ? num[i] : 0;
            digit += k % 10 + carry;
            k /= 10;
            carry = digit / 10;
            ret.push_back(digit % 10);
        } 
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
