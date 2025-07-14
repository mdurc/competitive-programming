class MedianFinder {
public:
    MedianFinder() { }
    
    void addNum(int num) {
        max_heap.push(num);
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
            // swap, move it to the larger half
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (max_heap.size() > min_heap.size() + 1) {
            // swap, keep halves even
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (min_heap.size() > max_heap.size() + 1) {
            // swap, keep halves even
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        } else if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return min_heap.top();
        }
    }
private:
    priority_queue<int> max_heap; // left (small half heap)
    priority_queue<int, vector<int>, greater<int>> min_heap; // right (large half heap)
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
