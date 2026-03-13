#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <unordered_map>
struct cmp{
    bool operator()(const std::pair<std::string,int>& a, const std::pair<std::string,int>& b){
        if(a.second==b.second){
            // lexicographical order
            return a.first < b.first;
        }else{
            // sort this way would make sure the top of the heap is the string with the lowest frequency.
            return a.second > b.second;
        }
    }
};
class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::vector<std::string> ret;
        std::unordered_map<std::string,int> m;
        for(const std::string& s: words){ ++m[s]; }

        std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>, cmp> pq;

        std::unordered_map<std::string,int>::const_iterator i=m.cbegin();
        for(;i!=m.cend();++i){
            pq.push(*i); 
            if(pq.size()>k){
                // get rid of the item that is the lowest frequency.
                // we are sorting with cmp to have lowest frequency at the top.
                pq.pop();
            }
        }

        for(;k>0 && !pq.empty();--k){
            ret.push_back(pq.top().first);
            pq.pop();
        }
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};
