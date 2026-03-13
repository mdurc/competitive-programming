class Solution {
public:
    void helper(TreeNode* p, TreeNode*& new_root, TreeNode*& curr){
        if(!p) return;
        helper(p->left,new_root,curr);
        if(!new_root){
            new_root=new TreeNode(p->val);
            curr=new_root;
        }else{
            curr->right=new TreeNode(p->val);
            curr=curr->right;
        }
        helper(p->right,new_root,curr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* new_root=nullptr;
        TreeNode* curr=nullptr;
        helper(root,new_root,curr);
        return new_root;
    }
};
