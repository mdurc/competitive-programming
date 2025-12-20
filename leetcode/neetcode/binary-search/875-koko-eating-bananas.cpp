class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we know: h >= piles.size()
        // we know: 1 <= ans <= max(piles)
        int max_val = 0;
        for (int i=0; i<piles.size(); ++i){
            if (piles[i] > max_val) max_val = piles[i];
        }
        int low = 1;
        int high = max_val;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long time = 0;
            for (int i=0; i<piles.size(); ++i){
                time += ceil((double)piles[i]/mid);
            }
            if (time > h){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};
