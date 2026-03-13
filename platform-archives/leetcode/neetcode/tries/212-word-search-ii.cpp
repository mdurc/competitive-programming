struct Node{
    Node* children[26];
    bool is_end;
    string word;
    Node (){
        for(int i=0; i<26; ++i){
            children[i] = nullptr;
        }
        is_end = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string& word) {
        Node* curr = root;
        for(char c : word){
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->is_end = true;
        curr->word = word;
    }
};

// time: O(m * n * 4 * 3^(t-1) + s)
// space: O(s)
// Where m is the number of rows, n is the number of columns, t is the maximum length of any word in the array words and s is the sum of the lengths of all the words.
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie tree;
        for(string& w : words){
            tree.insert(w);
        }

        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                dfs(board, i, j, tree.root, ans);
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, Node* p, vector<string>& ans){
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() ||
            board[i][j] == '.') return;

        char c = board[i][j];

        p = p->children[c - 'a'];
        if(!p) return;
        if(p->is_end){
            ans.push_back(p->word);
            p->is_end = false;
        }
        board[i][j] = '.';
        dfs(board, i-1, j, p, ans);
        dfs(board, i+1, j, p, ans);
        dfs(board, i, j-1, p, ans);
        dfs(board, i, j+1, p, ans);
        board[i][j] = c;
    }
};
