#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i:nums)
            s.insert(i);
        return *((s.size()<3)?--s.end():------s.end());
    }
};
