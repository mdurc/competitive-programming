// O(n) time and space
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root, &ans);
        return ans;
    }
private:
    int dfs(TreeNode* node, int* ans) {
        if (!node) return 0;
        int lm = max(0, dfs(node->left, ans));
        int rm = max(0, dfs(node->right, ans));
        *ans = max(*ans, node->val + lm + rm);
        return node->val + max(lm, rm);
    }
};
