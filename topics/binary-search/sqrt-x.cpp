// https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x/2 + 1;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (mid * mid >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return ((long long) l * l > x) ? l - 1 : l;
    }
};
