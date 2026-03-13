class Node {
public:
    /*
    Node* children[26];
    bool end_of_word;
    Node () {
        for (int i=0; i<26; ++i){
            children[i] = nullptr;
        }
        end_of_word = false;
    }
    */
    vector<Node*> children;
    bool end_of_word;
    Node(): children(26, nullptr), end_of_word(false) {}
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;
        for (char c: word){
            int index = c - 'a';
            if (curr->children[index] == nullptr){
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->end_of_word = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int j, Node* node){
        Node* curr = node;

        for (int i=j; i<word.size(); ++i){
            char c = word[i];
            if (c == '.'){
                for (Node* child : curr->children) {
                    if (child != nullptr && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            } else{
                if (curr->children[c-'a'] == nullptr){
                    return false;
                }
                curr = curr->children[c-'a'];
            }
        }
        return curr->end_of_word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
