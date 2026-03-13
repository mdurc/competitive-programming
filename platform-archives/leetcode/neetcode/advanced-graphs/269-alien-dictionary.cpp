class Solution {
public:
    string foreignDictionary(vector<string>& words) {
      // topological sort
      std::unordered_map<char, std::unordered_set<char>> adj;
      std::unordered_map<char, int> in_degree;
      for (const std::string& w: words) {
        for (char c: w) {
          in_degree[c] = 0;
        }
      }
      int n = (int)words.size();
      for (int i = 0; i+1 < n; ++i) {
        std::string w1 = words[i];
        std::string w2 = words[i+1];
        int len = std::min(w1.size(), w2.size());
        if (w1.size() > w2.size() && w1.substr(0, len) == w2) {
          return "";
        }
        for (int j = 0; j < len; ++j) {
          if (w1[j] != w2[j]) {
            if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
              adj[w1[j]].insert(w2[j]);
              in_degree[w2[j]]++;
            }
            break;
          }
        }
      }
      std::queue<char> q;
      for (auto [u, amt]: in_degree) {
        if (amt == 0) {
          q.push(u);
        }
      }
      std::string res = "";
      while (!q.empty()) {
        char u = q.front();
        q.pop();
        res += u;
        if (adj.count(u)) {
          for (char v: adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
              q.push(v);
            }
          }
        }
      }
      if (res.size() != in_degree.size()) {
        return "";
      }
      return res;
    }
};
