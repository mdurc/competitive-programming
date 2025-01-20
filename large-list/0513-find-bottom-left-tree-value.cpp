class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // breadth first search seems like the right idea
        vector<vector<int>> b;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int z=q.size();
            vector<int> lvl;
            for(int i=0;i<z;++i){
                TreeNode* next=q.front();
                if(next->left){ q.push(next->left); }
                if(next->right){ q.push(next->right); }
                lvl.push_back(q.front()->val);
                q.pop();
            }
            b.push_back(lvl);
        }
        return b.back().front();
    }
};
