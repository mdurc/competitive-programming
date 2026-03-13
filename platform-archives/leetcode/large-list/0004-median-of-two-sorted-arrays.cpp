
#include <iostream>
#include <vector>


class Solution {
public:
    
    Solution() {
        std::vector<int> nums1{1};
        std::vector<int> nums2{};
        std::cout<<findMedianSortedArrays(nums1,nums2);
    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        /*
         * steps: 
         * 1. Merge the two lists with a merge function
         * 2.5: Find the middle element (if sorted lists is odd length)
         *          length/2
         * 2.5: Find the avg of two middle elements (if even length)
         *          length/2 and length/2 - 1
         */

        
        std::vector<int> sorted{};
        if (nums1.size()==0){
            sorted = nums2;
        }else if (nums2.size()==0){
            sorted = nums1;
        }else{
            sorted = merge(nums1, nums2);
        }

        int length {static_cast<int>(sorted.size())};
        if (length % 2 != 0){
            return sorted[length/2] * 1.0;
        }else{
            return (sorted[length/2 - 1] + sorted[length/2])/2.0;
        }

        return 0;
    }


    std::vector<int> merge(std::vector<int>& l1, std::vector<int>& l2){
        int a{}, b{};
        bool adone{false}, bdone{false};
        std::vector<int> result{};
        while (!(adone&&bdone)){
            if (!adone && (bdone || l1[a]<l2[b])){
                result.push_back(l1[a]);
                a++;
                adone = a==l1.size();
            }else {
                result.push_back(l2[b]);
                b++;
                bdone = b==l2.size();
            }
        }
        return result;
    }


};

int main() { Solution(); }



