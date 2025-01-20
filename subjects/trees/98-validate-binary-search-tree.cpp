// O(n) time and O(n) space
class Solution {
public:
    bool dfs(TreeNode* node, long min_val, long max_val) {
        if (!node) return true;
        if (node->val <= min_val || node->val >= max_val){
            return false;
        }
        return dfs(node->left, min_val, node->val) &&
               dfs(node->right, node->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
