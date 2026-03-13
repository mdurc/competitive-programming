class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // n log n
        for (int n: stones) {
            pq.push(n);
        }

        // n log n
        while (pq.size() > 1) {
            int l = pq.top(); pq.pop();
            int r = pq.top(); pq.pop();
            int c = l - r;
            if (c != 0) {
                pq.push(c);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
