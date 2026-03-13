// Note to not allocate on heap, and note that we can use the nodes of
// list1 and list2 because as soon as we manipulate them, we are already moved on
// to their next nodes.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans;
        ListNode* temp = &ans;
        while (list1 && list2){
            if (list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1){
            temp->next = list1;
        }else{
            temp->next = list2;
        }
        return ans.next;
    }
};
