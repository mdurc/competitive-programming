class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(!root)return -1;

        // in order traversal is sorted.
        // keep going left to find the smallest value.

        int val=kthSmallest(root->left,k);
        if(val>=0){ return val; }

        // then check the node, if it is the one we want
        // then return it. Otherwise find the next in order value.
        if(k==1){ return root->val; }
        --k;

        // search right
        val=kthSmallest(root->right,k);
        if(val>=0){ return val; }
        return -1;
    }
};
