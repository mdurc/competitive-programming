class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // simply move through the bst until we reach a node where p and q exist on opposite branches below
        TreeNode* curr = root;
        while (curr) {
            if (p->val < curr->val && q->val < curr->val){
                curr = curr->left;
            }else if (p->val > curr->val && q->val > curr->val){
                curr = curr->right;
            }else{
                return curr;
            }
        }
        return nullptr;
    }
};
