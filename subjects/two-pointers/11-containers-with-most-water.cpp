class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max_area = 0;
        while (i<j){
            bool a = height[i] < height[j];
            if (a){
                max_area = max(max_area, height[i]*(j-i));
                ++i;
            }else{
                max_area = max(max_area, height[j]*(j-i));
                --j;
            }
        }
        return max_area;
    }
};
