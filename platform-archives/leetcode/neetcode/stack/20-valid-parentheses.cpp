class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> p = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> a;
        for(int i=0; i<s.size(); ++i){
            unordered_map<char,char>::iterator itr;
            itr = p.find(s[i]);
            if (itr != p.end()){
                if(a.empty() || a.top() != itr->second) return false;
                a.pop();
            }else{
                a.push(s[i]);
            }
        }
        return a.empty();
    }
};
