// time complexity: O(n), space: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size()-k+1);
        deque<int> q; // hold indices of max values
        int i = 0;
        int j = 0;

        // keep the left (back) side of the deque as the maximum nums value in window
        // monotonic decreasing queue
        while (j < nums.size()){
            // pop smaller values than the current rightmost val
            while (!q.empty() && nums[j] > nums[q.front()]){
                q.pop_front();
            }
            q.push_front(j);

            // remove left value from window if it is out of bounds
            if (i > q.back()){
                q.pop_back();
            }

            if ((j + 1) >= k){
                ans[i] = nums[q.back()];
                ++i;
            }
            ++j;
        }

        return ans;
    }
};


// time complexity: O(nlogn), space: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i){
            pq.push({nums[i], i});
            if (i >= k-1){
                while (pq.top().second <= i-k){ // only track max vals in range
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
