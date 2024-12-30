class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now at the midpoint
        ListNode* second = slow->next; // the start of the second half
        slow->next = nullptr; // make the first half end on nullptr here

        // reverse the second half
        ListNode* prev = nullptr;
        ListNode* temp;
        while (second){
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        // second is null, prev is the reversed head
        second = prev;

        // merge first and second half, keep head in-place
        temp = head;
        while (second){
            ListNode* t1 = temp->next;
            ListNode* t2 = second->next;

            temp->next = second;
            temp = t1;
            second->next = t1;
            second = t2;
        }
    }
};
