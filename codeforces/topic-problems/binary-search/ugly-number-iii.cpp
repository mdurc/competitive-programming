// https://leetcode.com/problems/ugly-number-iii/description/
typedef long long ll;
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab  = (ll)a * b / gcd(a, b);
        ll ac  = (ll)a * c / gcd(a, c);
        ll bc  = (ll)b * c / gcd(b, c);
        ll abc = (ll)a * bc / gcd(a, bc);
        ll l = 1, r = 2e9; // from constraints
        while (l < r) {
            ll mid = l + (r - l) / 2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
            if (cnt >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
