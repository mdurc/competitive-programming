#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    // the value will be stored as index 0 (a) through 25 (z)
    TrieNode* children[26];
    int times_traversed;
    TrieNode():times_traversed(0){
        for(int i=0;i<26;++i){
            children[i]=nullptr;
        }
    }
    bool contains(const char& c){ return children[c-'a']; }
    int& traversed_char(const char& c){return children[c-'a']->times_traversed;}
};
class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode;
    }
    ~Trie(){
        destroy_tree(root);
    }
    void destroy_tree(TrieNode* p){
        for(int i=0;i<26;++i){
            if(p->children[i]){
                destroy_tree(p->children[i]);
            }
        }
        delete p;
    }
    void insert(const string& word){
        // start from the root, check if the path exists,
        //   otherwise, make a new path
        TrieNode* temp = root;
        for(const char& c:word){
            if(temp->contains(c)){
                temp=temp->children[c-'a'];
                ++temp->times_traversed;
            }else{
                temp->children[c-'a']=new TrieNode;
                temp=temp->children[c-'a'];
                ++temp->times_traversed;
            }
        }
    }
    string search_common_prefix(const string& word,int num_words){
        TrieNode* temp = root;

        int z=word.size();

        for(int i=0;i<z;++i){
            const char& c=word[i];
            if(temp->contains(c)&&temp->traversed_char(c)==num_words){
                temp=temp->children[c-'a'];
            }else{
                return word.substr(0,i);
            }
        }
        return word;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* tree = new Trie;
        for(const string& s:strs){
            tree->insert(s);
        }
        string ret = tree->search_common_prefix(strs[0],strs.size());
        delete tree;
        return ret;
    }
};

int main(){
    Solution s;
    vector<string> v = {"floxwer","floxw","floxxight"};
    string x = s.longestCommonPrefix(v);
    cout << x << endl;
    return 0;
}

