
// O(n) time, O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        ret.push_back(1);
        // cut off the last because we never need to multiply all values in nums
        for(int i=0; i<nums.size()-1; ++i){
            ret.push_back(nums[i]*ret[ret.size()-1]);
        }

        int curr_backwards = 1;
        for(int i=ret.size()-1; i>=0; --i){
            ret[i] *= curr_backwards;
            curr_backwards *= nums[i];
        }
        return ret;
    }
};


// not O(1) space complexity, but O(n) time complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forwards, backwards;
        forwards.push_back(nums[0]);
        cout << forwards[0] << ' ';
        for(int i=1; i<nums.size(); ++i){
            forwards.push_back(nums[i]*forwards[forwards.size()-1]);
            cout << forwards[i] << ' ';
        }
        cout << '\n';
        backwards.push_back(nums[nums.size()-1]);
        cout << backwards[0] << ' ';
        for(int i=nums.size()-2; i>=0; --i){
            backwards.push_back(nums[i]*backwards[backwards.size()-1]);
            cout << backwards[backwards.size()-1] << ' ';
        }

        
        vector<int> ret;
        int i=0;
        int j=backwards.size()-2;
        ret.push_back(backwards[j]);
        --j;

        while(ret.size()!=nums.size()){
            if(j<0){
                ret.push_back(forwards[i]);
            }else{
                ret.push_back(forwards[i]*backwards[j]);
                ++i;
                --j;
            }
        }

        return ret;
    }
};
