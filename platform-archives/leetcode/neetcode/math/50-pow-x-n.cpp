class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        long b = abs((long)n);
        double res = 1;
        while (b) {
            if (b & 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return n > 0 ? res : 1 / res;
    }
};
