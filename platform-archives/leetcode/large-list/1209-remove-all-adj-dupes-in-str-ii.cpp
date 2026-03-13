#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int z=s.size();
        for(int i=0;i<z;++i){
            if(st.empty() || s[i] != st.top().first){
                st.push({s[i],1});
            }else if(++st.top().second == k){
                st.pop();
            }
        }

        s.clear();
        while(!st.empty()){
            s = string(st.top().second, st.top().first) + s;
            st.pop();
        }

        return s;
    }
};


int main(){
    Solution s;
    cout << s.removeDuplicates("aaaaabb",5) << endl;
    return 0;
}
