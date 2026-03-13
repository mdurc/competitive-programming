#define all(a) a.begin(),a.end()
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(all(gas),0) < accumulate(all(cost),0)) return -1;
        int n = gas.size();
        int res = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += (gas[i]-cost[i]);
            if (cur < 0) {
                cur = 0;
                res = i+1;
            }
        }
        return res;
    }
};
