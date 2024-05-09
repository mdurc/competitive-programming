#include <vector>
#include <map>
#include <set>
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::map<int, int> m;
        for(int n: arr){
            ++m[n];
        }
        std::map<int, int>::iterator itr = m.begin();
        std::set<int> s;
        for(; itr!=m.end(); ++itr){
            if(!s.insert(itr->second).second){
                return false;
            }
        }
        return true;
    }
};
