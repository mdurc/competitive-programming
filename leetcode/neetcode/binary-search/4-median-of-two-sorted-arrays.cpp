// time complexity: O(log(min(n,m))), space: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        // A is the smaller vector
        int i = 0;
        int j = A.size();
        while (i <= j) {
            int midA = (i + j) / 2;
            int midB = half - midA;

            int Aleft = (midA > 0) ? nums1[midA - 1] : INT_MIN;
            int Aright = (midA < nums1.size()) ? nums1[midA] : INT_MAX;

            int Bleft = (midB > 0) ? nums2[midB - 1] : INT_MIN;
            int Bright = (midB < nums2.size()) ? nums2[midB] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                // found the correct left partition
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                j = midA - 1;
            } else {
                i = midA + 1;
            }
        }
        return -1;
    }
};
