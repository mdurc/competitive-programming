class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq; // max heap, <distance, index>
        for (int i=0; i<points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};
