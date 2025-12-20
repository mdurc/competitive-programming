/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int& ret, TreeNode*& prev){
        if(!root) return;
        traverse(root->left,ret,prev);
        if(prev){
            ret = std::min(ret, abs(root->val-prev->val));
        }
        prev = root;
        traverse(root->right,ret, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        // in order traversal.
        // get difference of the next largest node vs curr node
        // O(n)
        int ret=INT_MAX;
        TreeNode* prev = nullptr;
        traverse(root, ret, prev);
        return ret;
    }
};
