
#include <bits/stdc++.h>
using namespace std;


// used for a min heap
// I need to use pairs so that i can compare index directly;
struct cmp{
    bool operator()(const pair<string,int>& a, const pair<string,int>& b){
        if(a.first.size()!=b.first.size())
            return a.first.size()>b.first.size();
        else
            return a.second>b.second;
    }
};
class Solution {
public:
    string arrangeWords(string text) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> p;
        // parse
        text[0]=tolower(text[0]);
        stringstream ss(text);
        string word;
        int ind=0;
        while(ss>>word){
            p.push({word,ind});
            ++ind;
        }

        pair<string,int> first = p.top();
        first.first[0]=toupper(first.first[0]);
        text=first.first;
        p.pop();
        while(!p.empty()){
            text+= ' ' + p.top().first;
            p.pop();
        }
        return text;
    }
};
