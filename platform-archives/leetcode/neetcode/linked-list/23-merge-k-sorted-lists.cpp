/*
If you just merge them left to right the time complexity is:
    - Let $T(i)$ be the time to merge arrays 1 to $i$. Then we know that $T(i) <= T(i-1) + c n i$. Thus $T(k) <= t_1 + c n sum_(i=2)^k i = O(n k^2)$
Better version (divide and conquer):
    - Divide the arrays into two sets each with $k/2$ arrays. Recursively merge the arrays where the base case is $k = 1$. Time is $T(k) = 2T(k/2) + O(n k) ==> O(n k log k)$
*/

// Straightforward divide and conquer
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }
private:
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) { return nullptr; }
        if (l == r) { return lists[l]; }
        int mid = l + (r - l) / 2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);
        return conquer(left, right);
    }
    ListNode* conquer(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }
        return dummy.next;
    }
};


// Doing mergesort way by divide and conquer, iteratively. time: O(n*log(k)), space: O(k)
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



// Full iterative solution. time: O(n*k), space: O(1)
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
