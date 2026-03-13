
#include <iostream>
#include <vector>




class Solution {
public:
    Solution(){
        std::cout<<isPalindrome(2147483647);
    }
    bool isPalindrome(int x) {

        if (x<0){
            return false;
        }else if(x==0){
            return true;
        }

        std::vector<int> nums{};

        //345
        //34 r: 5
        //3  r: 4
        //3  r: 3
        //0  exit
        while(x>0){
            nums.push_back(x%10);
            x = x/10;
        }

        size_t times{nums.size()/2};

        int curr_index {};
        int last_index {int(nums.size())-1};
        for (int i{}; i < times; i++){
            if (nums[curr_index]!=nums[last_index]){
                return false;
            }
            curr_index++;
            last_index--;
        }


        return true;
    }
};


int main(){
    Solution();

    return 0;
}
