// in-order traversal but ending after reading the kth node
// O(n) time and space
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        dfs(root, &k, &ans);
        return ans;
    }
    void dfs(TreeNode* node, int* k, int* ans){
        if (!node) return;
        dfs(node->left, k, ans);
        if (--(*k) == 0){
            *ans = node->val;
            return;
        }
        dfs(node->right, k, ans);
    }
};

// in-order traversal of the BST: O(n) time and O(n) space
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, ans);
        return ans[k-1];
    }
    void dfs(TreeNode* node, vector<int>& ans){
        if (!node) return;
        dfs(node->left, ans);
        ans.push_back(node->val);
        dfs(node->right, ans);
    }
};
