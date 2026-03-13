
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // just a breadth first search
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int z=q.size();
            for(int i=0;i<z;++i){
                TreeNode* f = q.front();
                temp.push_back(f->val);
                if(f->left){q.push(f->left);}
                if(f->right){q.push(f->right);}
                q.pop();
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
