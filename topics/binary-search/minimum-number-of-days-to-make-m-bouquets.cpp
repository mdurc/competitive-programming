// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
class Solution {
public:
    bool valid(vector<int>& bloom, int m, int k, int days) {
        int curr = 0;
        for (int b: bloom) {
            if (b <= days) {
                if (++curr == k) {
                    curr = 0;
                    --m;
                }
            } else {
                curr = 0;
            }
        }
        return m <= 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(bloomDay, m, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return valid(bloomDay, m, k, l) ? l : -1;
    }
};
