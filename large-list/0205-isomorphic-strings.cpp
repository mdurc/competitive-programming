
#include <map>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int size = s.size();
        if (size != t.size()) return false;

        std::map<char, char> swap;

        // swap the letters of "s" with the letters of "t"
        for (int i = 0; i < size; ++i) {
            std::pair<std::map<char, char>::const_iterator, bool> ret =
                swap.insert(std::make_pair(t[i], s[i]));
            if(!ret.second && swap[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};
