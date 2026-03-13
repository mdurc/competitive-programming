
#include </usr/local/include/bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;
        stack<ListNode*> s;
        ListNode* temp = head;
        while(temp){
            s.push(temp);
            temp = temp->next;
        }
        ListNode* next=nullptr;
        while(!s.empty() && n){
            if(n==1){
                next=s.top();
            }
            --n;
            s.pop();
        }
        if(s.empty()) return head;
        s.top()->next=next;
        return head;
    }
};
