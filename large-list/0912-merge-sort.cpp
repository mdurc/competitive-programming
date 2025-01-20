class Solution {
public:
    vector<int> merge(vector<int>& v1, vector<int>& v2){
        int size1 = v1.size();
        int size2 = v2.size();
        std::vector<int> v(size1+size2, 0);
        int index1 = 0;
        int index2 = 0;
        int index = 0;
        // traverse v1 and v2 at the same time
        while(index1<size1 && index2<size2){
            // whoever is smaller goes to v
            if(v1[index1]<v2[index2]){
                v[index] = v1[index1];
                index1 = index1 + 1;
            }else{
                v[index] = v2[index2];
                index2 = index2 + 1;
            }
            index = index + 1;
        }
    
        // if v1 is done, let's now deal with v2 left overs
        if(index1>=size1){
            while(index2<size2){
                v[index] = v2[index2];
                index++;
                index2++;
            }
        }else{
            // else means v2 is done. let's now deal with v1 left overs
            while(index1<size1){
                v[index] = v1[index1];
                index++;
                index1++;
            }
        }
        return v;
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        int mid = nums.size()/2;
        std::vector<int> left(mid, 0);
        std::vector<int> right(nums.size()-mid, 0);
        for(int i = 0 ; i < mid;i++){
            left[i] = nums[i];
        }
        for(int i = mid ; i < nums.size();i++){
            right[i-mid] = nums[i];
        }

        left = sortArray(left);
        right = sortArray(right);
        return merge(left, right);
    }
};
