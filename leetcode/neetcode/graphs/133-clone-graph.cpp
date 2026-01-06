/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
      std::map<int, Node*> seen;
      auto dfs = [&](auto&& dfs, Node* u) -> Node* {
        if (!u) return nullptr;
        Node* res = new Node(u->val);
        seen[u->val] = res;
        for (Node* v: u->neighbors) {
          auto itr = seen.find(v->val);
          res->neighbors.push_back(itr == seen.end() ? dfs(dfs,v): itr->second);
        }
        return res;
      };
      return dfs(dfs, node);
    }
};
