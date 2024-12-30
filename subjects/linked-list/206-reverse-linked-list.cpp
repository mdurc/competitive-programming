// recursive solution; time: O(n), space: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev=nullptr) {
        if (!head) return prev;
        ListNode* temp = head->next;
        head->next = prev;
        return reverseList(temp, head);
    }
};


// iterative solution; time: O(n), space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while (head->next){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head->next = prev;
        return head;
    }
};
