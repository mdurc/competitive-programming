#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int sz = nums.size();
        if(sz==0) return 0;

        std::unordered_set<int> arr;

        for(int i=0;i<sz;++i){
            arr.insert(nums[i]);
        }

        int max_length = 0;
        // For each "starting" num, go through the hash and look for the next value.
        // Keep track of the length every "next" that you go to.
        std::unordered_set<int>::const_iterator i=arr.begin();
        for(;i!=arr.end();++i){
            // check if it is the start of a sequence first.
            if(!arr.count(*i-1)){
                int next = *i+1;
                while(arr.count(next)){
                    ++next;
                }
                max_length = std::max(max_length,next-*i);
            }
        }
        return max_length;
    }
};


