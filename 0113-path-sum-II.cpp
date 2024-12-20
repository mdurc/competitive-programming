
class Solution {
public:
    void helper(TreeNode* p, vector<int> curr, int sum, int t, vector<vector<int>>& r){
        if(!p) return;
        if(!p->left && !p->right){
            if(sum+p->val==t){
                curr.push_back(p->val);
                r.push_back(curr);
            }
            return;
        }
        curr.push_back(p->val);
        helper(p->left,curr,sum+p->val,t,r);
        helper(p->right,curr,sum+p->val,t,r);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        helper(root,{},0,targetSum,ret);
        return ret;
    }
};
