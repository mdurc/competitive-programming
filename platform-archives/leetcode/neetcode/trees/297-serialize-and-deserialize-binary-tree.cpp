/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs_serialize(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 1;
        return dfs_deserialize(data, i);
    }
private:
    void dfs_serialize(TreeNode* node, string& ans){
        if (!node){
            ans += ",N";
            return;
        }
        ans += "," + to_string(node->val);
        dfs_serialize(node->left, ans);
        dfs_serialize(node->right, ans);
    }
    TreeNode* dfs_deserialize(string& data, int& i){
        // account for negative numbers
        if (i >= data.size() || data[i] == 'N'){
            i += 2; // move past comma
            return nullptr;
        }
        size_t next_comma = data.find(",", i);
        if (next_comma == std::string::npos){
            next_comma = data.size();
        }
        string part = data.substr(i, next_comma-i);
        i = next_comma + 1;

        TreeNode* node = new TreeNode(stoi(part));
        node->left = dfs_deserialize(data, i);
        node->right = dfs_deserialize(data, i);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
