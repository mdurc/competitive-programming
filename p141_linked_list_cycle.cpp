/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        // Check current and next, so we dont do `null->next` inside while
        while (p2 != nullptr && p2->next != nullptr) {
            // walk one step forward
            p1 = p1->next;
            // walk two steps forward
            p2 = p2->next;
            p2 = p2->next;

            //p2 will loop through and eventually catch up to p1 from behind
            //This will signify that there is a loop somewhere
            if (p1 == p2) {
                return true;
            }
            // or we will reach a nullptr which removes the chance for a loop
        }
        return false;
    }
};
