// My original solution:
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,pair<int,int>> m;
        int n = s.size();
        for (int i = 0; i < n ; ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = make_pair(i,i);
            } else {
                m[s[i]].second = i;
            }
        }
        vector<pair<int,int>> ranges;
        for (auto& [_, pos]: m) {
            ranges.push_back(pos);
        }
        sort(ranges.begin(),ranges.end());
        pair<int,int> prev = ranges[0];
        vector<int> res;
        for (int i = 1; i < ranges.size(); ++i) {
            if (prev.second < ranges[i].first) { // disjoint
                res.push_back(prev.second-prev.first+1);
                prev = ranges[i];
            } else {
                prev.second = max(prev.second, ranges[i].second);
            }
        }
        res.push_back(prev.second-prev.first+1);
        return res;
    }
};

// Simpler solution:
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int> m;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            m[s[i]] = i;
        }
        vector<int> res;
        int len = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            ++len;
            end = max(end, m[s[i]]);
            if (i == end) {
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};
