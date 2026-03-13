// O(n) monotonic decreasing stack problem
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        // keep track of value and index(for idx distance)
        stack<pair<int,int>> s;
        for (int i=0; i<temperatures.size(); ++i){
            while (!s.empty() && temperatures[i] > s.top().first){
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return ans;
    }
};


// O(n^2) inefficient solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);

        for (int i=0; i<temperatures.size(); ++i){
            for (int j=i+1; j<temperatures.size(); ++j){
                if (temperatures[j] > temperatures[i]){
                    ans[i] = j-i;
                    break;
                }
            }
        }
        return ans;
    }
};
