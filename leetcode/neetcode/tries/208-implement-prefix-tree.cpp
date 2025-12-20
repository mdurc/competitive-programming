class Node {
public:
    Node* children[26];
    bool end_of_word;
    Node () {
        for (int i=0; i<26; ++i){
            children[i] = nullptr;
        }
        end_of_word = false;
    }
    /*
    vector<Node*> children;
    bool end_of_word;
    Node(): children(26, nullptr), end_of_word(false) {}
    */
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* curr = root;
        for (char c: word){
            int index = c - 'a';
            curr = curr->children[index];
            if (!curr) return false;
        }
        return curr->end_of_word;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c: prefix){
            int index = c - 'a';
            curr = curr->children[index];
            if (!curr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
