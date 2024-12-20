

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    // brute force:
    int countVowelSubstrings(string w){
        unordered_set<char> s;
        int ret=0;
        int z=w.size();
        for(int i=0;i<z;++i){
            for(int j=i;j<z;++j){
                if(isVowel(w[j])){
                    s.insert(w[j]);
                    ret+=s.size()==5;
                }else{ break; }
            }
            s.clear();
        }
        return ret;
    }
};

int main(){
    Solution s;
    map<string,int> tests = { {"poazaeuioauoiioaouuouaui",31}, {"aeiouu",2}, {"unicornarihan",0}, {"cuaieuouac",7}, {"unicornarihane",0}};
    map<string,int>::iterator itr = tests.begin();
    for(;itr!=tests.end();++itr){
        int ans = s.countVowelSubstrings(itr->first);
        std::cout << itr->first << ": " << ans << ", intended: " << itr->second << std::endl;
        assert(ans==itr->second);
    }

    return 0;
}
