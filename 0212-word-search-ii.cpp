#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* children[26];
    bool is_end;
    string word;
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
        temp->word=word;
    }
};

class Solution {
public:
    void search(vector<vector<char>>& board, int i, int j, Node* p, vector<string>& ret){
        if(i<0||j<0||i>=board.size()||j>=board[i].size()){
            return;
        }
        if(board[i][j]=='.'){return;}

        char c=board[i][j];
        p=p->children[c-'a'];
        if(!p){return;}
        if(p->is_end){
            ret.push_back(p->word);
            p->is_end=0;
        }
        board[i][j]='.';
        search(board,i-1,j,p,ret);
        search(board,i+1,j,p,ret);
        search(board,i,j-1,p,ret);
        search(board,i,j+1,p,ret);
        board[i][j]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        Trie tree;
        for(const string& w:words){
            tree.insert(w);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                search(board, i, j, tree.root, ret);
            }
        }
        return ret;
    }
};
