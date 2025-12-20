class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        while(temp){
            if(val<temp->val){
                if(!temp->left){
                    temp->left=new TreeNode(val);
                    return root;
                }
                temp=temp->left;
            }else{
                if(!temp->right){
                    temp->right=new TreeNode(val);
                    return root;
                }
                temp=temp->right;
            }
        }
        if(!root){ root=new TreeNode(val); }
        return root;
    }
};
