#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int recur_sum(TreeNode* root,unordered_map<int,int>& m,int& max_freq){
        if(!root){return 0;}
        if(!root->left && !root->right){
            max_freq=std::max(max_freq,++m[root->val]);
            return root->val;
        }
        int sum=root->val+recur_sum(root->left,m,max_freq)+recur_sum(root->right,m,max_freq);
        max_freq=std::max(max_freq,++m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        unordered_map<int,int> m;
        int max_freq=0;
        recur_sum(root,m,max_freq);
        unordered_map<int,int>::iterator i=m.begin();
        for(;i!=m.end();++i){
            if(i->second==max_freq){
                ret.push_back(i->first);
            }
        }
        return ret;
    }
};
