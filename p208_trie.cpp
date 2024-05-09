#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* children[26];
    bool is_end;
    Node():is_end(0){
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node;
    }
    void insert(const string& word) {
        Node* temp = root;
        for(const char& c:word){
            if(temp->children[c-'a']){
                temp=temp->children[c-'a'];
            }else{
                temp->children[c-'a']=new Node;
                temp=temp->children[c-'a'];
            }
        }
        temp->is_end=1;
    }
    bool search(const string& word) {
        Node* temp=root;
        for(const char& c:word){
            if(!temp->children[c-'a']){
                return 0;
            }
            temp=temp->children[c-'a'];
        }
        return temp->is_end;
    }
    bool startsWith(const string& prefix) {
        Node* temp=root;
        for(const char& c:prefix){
            if(!temp->children[c-'a']){
                return 0;
            }
            temp=temp->children[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
