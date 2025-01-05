
// Doing mergesort way by divide and conquer. time: O(n*log(k)), space: O(k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1){
            vector<ListNode*> merged;
            for (int i=0; i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1) < lists.size() ? lists[i+1] : nullptr;
                merged.push_back(merge(l1, l2));
            }
            lists = merged;
        }
        return lists[0];
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy;
        ListNode* temp = &dummy;
        while (l1 && l2){
            if (l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1){
            temp->next = l1;
        }else if (l2){
            temp->next = l2;
        }

        return dummy.next;
    }
};



// Iteration. time: O(n*k), space: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ans;
        ListNode* curr = &ans;

        int heads = lists.size();
        int nulls = 0;
        for (int i=0; i<heads; ++i){
            if (lists[i] == nullptr){
                ++nulls;
            }
        }

        while (nulls != heads){
            // find minimum of all heads
            // make that the new next
            int m = INT_MAX;
            int m_index = -1;
            for (int i=0; i<heads; ++i){
                if (lists[i] == nullptr) continue;
                if (lists[i]->val < m){
                    m = lists[i]->val;
                    m_index = i;
                }
            }
            curr->next = lists[m_index];
            curr = curr->next;

            lists[m_index] = lists[m_index]->next;
            if(lists[m_index] == nullptr){
                ++nulls;
            }
        }

        return ans.next;
    }
};
