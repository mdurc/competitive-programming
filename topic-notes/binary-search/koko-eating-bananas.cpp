// https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:
    bool valid(vector<int>& piles, int k, int h) {
        for (int p: piles) {
            h = h - (p + k - 1) / k; // ceiling
        }
        return h >= 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
