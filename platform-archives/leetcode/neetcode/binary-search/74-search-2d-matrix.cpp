class Solution {
public:
    // O(logn + logm) == O(log(n*m))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search vertically and horizontally
        int i = 0;
        int j = matrix.size();
        while (i<j){
            int mid = i + (j-i)/2;
            if (target < matrix[mid][0]){
                j = mid;
            }else{
                i = mid + 1;
            }
        }
        i -= 1; // adjust to the target of binary search

        // confirm result
        if (!(i>=0 && target >= matrix[i][0] && target <= matrix[i].back()))
            return false;

        int low=0;
        int high = matrix[i].size();
        while(low<high){
            int mid = low + (high-low)/2;
            if (target == matrix[i][mid]){
                return true;
            }else if (target < matrix[i][mid]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};
