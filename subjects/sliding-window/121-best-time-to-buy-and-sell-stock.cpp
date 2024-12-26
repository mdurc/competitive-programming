class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int ans = 0;
        while (j<prices.size()){
            int curr = prices[j]-prices[i];
            ans = max(ans,curr);
            if (curr < 0){
                i = j;
            }
            ++j;
        }
        return ans;
    }
};
