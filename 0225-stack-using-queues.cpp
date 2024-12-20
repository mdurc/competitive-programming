#include <bits/stdc++.h>
using namespace std;

class MyStack{
public:
    MyStack(){}
    void push(int x){
        int z=q.size();
        q.push(x);
        for(;z;--z){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int t=q.front();
        q.pop();
        return t;
    }
    int top(){return q.front();}
    bool empty(){return q.empty();}
    queue<int> q;
};
