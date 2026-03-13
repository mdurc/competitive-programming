#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // equivalent to std::greater<int>
    struct cmp { bool operator()(int a,int b) {return a>b;} };
    // O(nlogn + n)
    vector<int> sortArray(vector<int>& nums) {
        // really we could just do priority queue.
        // A min heap by using std::greater<int>, instead
        //  of the default std::less<int> which would make it a max heap.
        vector<int> ret;
        priority_queue<int,vector<int>,greater<int>> pq;
        // or cmp instead of greater<int>
        // if a is on top, if it is greater than b (element below it), then
        //      swap them (return true);
        for(int n: nums)
            pq.push(n);

        // and then pop out everything.
        while(!pq.empty()){
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }

    void percolate_down(vector<int>& nums, int n, int i){
        int index_w_largest=i;
        int left_index = i*2+1;
        int right_index = i*2+2;
        if(left_index<n&&nums[left_index]>nums[index_w_largest]){
            index_w_largest = left_index;
        }
        if(right_index<n&&nums[right_index]>nums[index_w_largest]){
            index_w_largest = right_index;
        }
        if(index_w_largest!=i){
            std::swap(nums[i],nums[index_w_largest]);
            // percolate_down the previously nums[i], to get to the very bottom.
            percolate_down(nums,n,index_w_largest);
        }
    }

    vector<int> sortArray_heap(vector<int>& nums){
        // the idea is to percolate_down to find the largest
        // value and put it at the top. Then move it to the end
        // of the array and exclude it from the next percolate_down,
        // finding all of the max values within every sub-array,
        // therefore finding the sorted order.
        int n = nums.size();
        // start from the parent of the last node of the heap: (n-2)/2
        for(int i=(n-2)/2;i>=0;--i){
            percolate_down(nums,n,i);
        }
        // make sure that i doesn't go out of bounds
        for(int i=0;i<n-1;++i){
            // put the next largest value at the end
            std::swap(nums[0],nums[n-1-i]);

            // Only percolate_down the first part, exclude the accurate end of the vector.
            // Index start at zero which will be the next one we have to adjust.
            percolate_down(nums,n-1-i,0);
        }
        return nums;
    }
};

int main() {
    Solution();
}
