class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max_left = height[i];
        int max_right = height[j];
        int ans = 0;
        while (i<j){
            if (max_left < max_right){
                ++i;
                max_left = max(max_left, height[i]);
                ans += max_left - height[i];
            }else{
                --j;
                max_right = max(max_right, height[j]);
                ans += max_right - height[j];
            }
        }
        return ans;
    }
};
