class Solution {
public:
    void traverse(TreeNode* root, int& ret, TreeNode*& prev){
        if(!root) return;
        traverse(root->left,ret,prev);
        if(prev){
            ret = std::min(ret, root->val-prev->val);
        }
        prev = root;
        traverse(root->right,ret, prev);
    }
    int minDiffInBST(TreeNode* root) {
        // in order traversal.
        // get difference of the next largest node vs curr node
        // O(n)
        int ret=INT_MAX;
        TreeNode* prev = nullptr;
        traverse(root, ret, prev);
        return ret;
    }
};
