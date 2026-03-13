

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){ return 0; }
        // check to see if left is !nullptr. Check if it is a leaf, if so,
        // add it to the sum that is returned.
        return ((root->left && !root->left->left && !root->left->right)?
                    root->left->val:0)+
                sumOfLeftLeaves(root->left)+
                sumOfLeftLeaves(root->right);
    }
};
