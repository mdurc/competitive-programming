// brute force; time: O(n^2), space: O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left-right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int height(TreeNode* node){
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

// dfs; time: O(n), space: O(h)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
private:
    vector<int> dfs(TreeNode* root){
        if (!root) return {1, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        bool balanced = (left[0] == 1 && right[0] == 1) &&
                        (abs(left[1] - right[1]) <= 1);
        int height = 1 + max(left[1], right[1]);
        return {balanced ? 1: 0, height};
    }
};
