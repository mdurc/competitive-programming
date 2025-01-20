#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    MyQueue(){}
    void push(int x){
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        temp.push(x);
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
    int pop(){
        int t=s.top();
        s.pop();
        return t;
    }
    int peek(){ return s.top(); }
    bool empty(){ return s.empty(); }
    stack<int> s;
    stack<int> temp;
};
