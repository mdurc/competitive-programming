// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
class Solution {
public:
    bool valid(vector<int>& weights, int cap, int days) {
        int mx = *max_element(weights.begin(), weights.end());
        if (mx > cap) return false;
        int curr = 0;
        for (int w: weights) {
            if (curr + w > cap) {
                curr = 0;
                --days;
            }
            curr += w;
        }
        return days > 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int l = 0, r = sum;
        // 0 weight FFFF TTTT 100000 weight
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(weights, mid, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
