// O(n) time and space complexity
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> real_to_copy;
        real_to_copy[NULL] = NULL;

        Node* temp = head;
        while (temp){
            Node* copy = new Node(temp->val);
            real_to_copy[temp] = copy;
            temp = temp->next;
        }

        temp = head;
        while (temp){
            Node* copy = real_to_copy[temp];
            copy->next = real_to_copy[temp->next];
            copy->random = real_to_copy[temp->random];
            temp = temp->next;
        }
        return real_to_copy[head];
    }
};
