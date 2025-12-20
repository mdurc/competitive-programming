class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        // the carry value simply moves forward, as
        // we are adding from left to right.
        int carry = 0;
        while (l1!=nullptr || l2!=nullptr || carry!=0){
            int v1 = (l1!=nullptr) ? l1->val : 0;
            int v2 = (l2!=nullptr) ? l2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(val);

            cur = cur->next;
            l1 = (l1!=nullptr) ? l1->next : nullptr;
            l2 = (l2!=nullptr) ? l2->next : nullptr;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
