// with ordered map
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();++i){
            ++freq[nums[i]];
        }
        map<int,vector<int>> m;
        unordered_map<int,int>::iterator j = freq.begin();
        for(;j!=freq.end(); ++j){
            m[j->second].push_back(j->first);
        }
        map<int,vector<int>>::iterator iter = --m.end();
        vector<int> ret;
        while(ret.size() != k){
            for (int i=0;i<iter->second.size();++i){
                ret.push_back(iter->second[i]);
                if(ret.size() == k) break;
            }
            --iter;
        }
        return ret;
    }
};


// with priority queue, the intended:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();++i){
            ++freq[nums[i]];
        }
        priority_queue<pair<int,int>> pq; // max heap
        unordered_map<int,int>::iterator iter;
        for(iter=freq.begin(); iter!=freq.end(); ++iter){
            // pq will sort by the first element of pair: frequency
            pq.push({iter->second, iter->first});
        }
        vector<int> ret;
        while(ret.size() != k && !pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

