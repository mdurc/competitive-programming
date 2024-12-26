// monotonic increasing stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // keep adding areas until we reach a bar that is too short to extend to
        int max_area = 0;
        stack<pair<int,int>> s; // index, height
        for (int i=0; i<heights.size(); ++i){
            int start = i;
            while (!s.empty() && s.top().second > heights[i]){
                pair<int,int> t = s.top();
                max_area = max(max_area, t.second * (i-t.first));
                start = t.first; // extend backwards
                s.pop();
            }
            s.push({start, heights[i]});
        }
        // check for rectangles that extend all to the end of histogram
        while (!s.empty()){
            pair<int,int> t = s.top();
            // the stack should be sorted low to high
            max_area = max(max_area, t.second * ((int)heights.size() - t.first));
            s.pop();
        }
        return max_area;
    }
};
