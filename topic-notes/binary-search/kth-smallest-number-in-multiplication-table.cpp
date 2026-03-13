// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
class Solution {
public:
    bool valid(int m, int n, int k, int num) {
        // check if there are at least k elements <= num
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            int add = min(num / i, n);
            if (add == 0) break;
            cnt += add;
        }
        return cnt >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(m, n, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
