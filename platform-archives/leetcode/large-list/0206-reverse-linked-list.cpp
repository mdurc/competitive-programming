
#include <stack>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList_ITERATIVE(ListNode* head) {
        if(!head||!head->next) return head;
        std::stack<ListNode*> s;
        ListNode* temp = head;
        while(temp->next){
            s.push(temp);
            temp=temp->next;
        }
        //temp is at the end
        ListNode* reverse = s.top();
        temp->next=reverse;
        s.pop();
        while(!s.empty()){
            reverse->next=s.top();
            reverse = s.top();
            s.pop();
        }
        reverse->next=nullptr;
        return temp;
    }
};

class OtherSolution{
public:
    ListNode* reverseList_RECURSIVE(ListNode* head, ListNode* prev=nullptr) {
        if(!head) return prev;
        ListNode* temp = head->next;
        head->next=prev;
        return reverseList_RECURSIVE(temp,head);
    }

};
