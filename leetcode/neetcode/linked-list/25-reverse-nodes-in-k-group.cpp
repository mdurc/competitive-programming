/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// time: O(n), space: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode* previous_group = &dummy;
        
        while (true){
            ListNode* kth = getKth(previous_group, k);
            if (!kth) break;

            ListNode* next_group = kth->next;

            // connect the start of this, to the start of the next group
            ListNode* prev = kth->next;

            ListNode* curr = previous_group->next;
            // reverse k-nodes
            for (int i=0; i<k; ++i){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = previous_group->next;
            previous_group->next = kth;
            previous_group = temp;
        }
        return dummy.next;
    }
private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k>0){
            curr = curr->next;
            --k;
        }
        return curr;
    }
};
