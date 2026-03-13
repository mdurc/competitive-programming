
// DFS with global variable
class Solution {
public:
    int ans = 0;
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        // do a dfs to find path and keep track of the current max
        dfs(root, root->val);
        return ans;
    }
    void dfs(TreeNode* node, int max_value){
        if (!node) return;
        if (node->val >= max_value){
            ++ans;
            max_value = node->val;
        }
        dfs(node->left, max_value);
        dfs(node->right, max_value);
    }
};

// DFS with no global
class Solution {
public:
    int goodNodes(TreeNode* root) {
        // do a dfs to find path and keep track of the current max
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int max_value){
        if (!node) return 0;
        int ans = (node->val >= max_value) ? 1 : 0;
        max_value = max(max_value, node->val);
        ans += dfs(node->left, max_value);
        ans += dfs(node->right, max_value);
        return ans;
    }
};
