// O(mlog k) time, O(k) space
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k){
        // we could keep a max heap of scores and then just check the third 
        // element each time after insertion, but this seems unecessary.
        // keep a min heap of scores instead.
        for (int n : nums) {
            add(n);
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
