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

// in-place depth first: time: O(n), space: O(1)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    void invert(TreeNode* root){
        if (!root) return;
        // swap left and right childrens
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
};

// depth first: time: O(n), space: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* node = new TreeNode(root->val);
        node->right = invertTree(root->left);
        node->left = invertTree(root->right);

        return node;
    }
};

// depth first non-recursive: time: O(n), space: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            swap(node->left, node->right);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        return root;
    }
};

// breadth first: time: O(n), space: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
