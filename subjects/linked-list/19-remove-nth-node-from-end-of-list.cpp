// Two pass solution; time: O(size), space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;

        int size = 0;
        ListNode* temp = head;
        while (temp){
            ++size;
            temp = temp->next;
        }

        if (size-n == 0){
            return head->next;
        }

        temp = head;
        for(int i=0; i < size-n-1; ++i){
            temp = temp->next;
        }
        // skip over the next node
        temp->next = temp->next->next;
        return head;
    }
};

// Note that it is possible to do it in one pass
// Use a node that moves n spaces to the right, and then start moving another
// node with it. When the right node reaches null, the left one is the node directly
// before the one we want to remove.
