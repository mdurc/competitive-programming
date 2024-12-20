#include <string>
#include <iostream>
using namespace std;
class Node{
public:
    Node(): next(nullptr), prev(nullptr){}
    Node* next;
    Node* prev;
    string val;
};
class BrowserHistory {
private:
    Node* head = new Node;
public:
    BrowserHistory(string homepage){
        head -> val = homepage;
    }
    string link(){
        return head->val;
    }
    
    void visit(string url) {
        Node* tmp = head->next;
        Node* advanced;
        while(tmp!=nullptr){
            advanced = tmp->next;
            delete tmp;
            tmp = advanced;
        }
        head -> next = new Node;
        head -> next -> val = url;
        head -> next -> prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        int count = 0;
        while(head->prev!=nullptr && count < steps){
            head = head->prev;
            count++;
        }
        return head->val;
    }
    
    string forward(int steps) {
        int count = 0;
        while(head->next!=nullptr && count < steps){
            head = head->next;
            count++;
        }
        return head->val;
    }
};

int main(){
  BrowserHistory* obj = new BrowserHistory("leetcode.com");
  obj->visit("google.com");
  obj->visit("facebook.com");
  obj->visit("youtube.com");
  string param_1 = obj->back(1);
  cout<<obj->link()<<endl;
  string param_2 = obj->back(1);
  string param_3 = obj->forward(1);
  obj->visit("linkedin.com");
  string param_4 = obj->forward(2);
  string param_5 = obj->back(2);
  string param_6 = obj->back(7);


 cout<< param_1<<", "<<param_2 << ", " << param_3<< ", " <<param_4<<", "<<param_5 << ", "<<param_6<< endl;
}
