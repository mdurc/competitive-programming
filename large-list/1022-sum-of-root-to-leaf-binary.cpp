
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
    int convertBinary(const string& b){
        int z=b.size();
        int ret=0;
        for(int i=z-1;i>=0;--i){
            if(b[i]-'0'){
                ret+=pow(2,z-i-1);
            }
        }
        return ret;
    }
    void findSum(TreeNode* node, int& sum, string binary=""){
        if(!node) return;
        binary+=to_string(node->val);
        if(!node->left && !node->right){
            sum+=convertBinary(binary);
        }
        findSum(node->left,sum,binary);
        findSum(node->right,sum,binary);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        findSum(root,sum);
        return sum;
    }
};

int main(){
    // [1,0,1,0,1,0,1]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);
    Solution s;
    std::cout << s.sumRootToLeaf(root) << std::endl;
    return 0;
}
