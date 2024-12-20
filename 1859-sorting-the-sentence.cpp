#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        int i, count=0;

        string temp, arr[9]; // max 9 words in sentence
        stringstream ss(s);
        while(ss >> temp){
            arr[temp.back()-'1'] = temp.substr(0,temp.size()-1);
            ++count;
        }

        temp.clear();
        for(i=0;i<count;++i) temp += i==0?arr[i]:' ' + arr[i];

        return temp;
    }
};

int main(){
    Solution s;
    cout << s.sortSentence("is2 sentence4 This1 a3") << endl;
    cout << s.sortSentence("Myself2 Me1 I4 and3") << endl;
    return 0;
}
