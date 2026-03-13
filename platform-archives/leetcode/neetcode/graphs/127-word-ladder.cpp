// Slow O(n^2) graph construction into bfs, still passes
const int mxn = 5000;
std::vector<int> adj[mxn];
int dist[mxn];
class Solution {
public:
    bool diff_one(std::string& a, std::string& b) {
      int n = (int)a.size();
      bool found = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
          if (found) return false;
          found = 1;
        }
      }
      return found;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      int start = 0;
      auto itr = std::find(wordList.begin(), wordList.end(), beginWord);
      if (itr == wordList.end()) {
        wordList.push_back(beginWord);
        start = (int)wordList.size()-1;
      } else {
        start = itr-wordList.begin();
      }
      int e = -1, n = wordList.size();
      for (int i = 0; i < n; ++i) adj[i].clear();
      for (int i = 0; i < n; ++i) {
        if (wordList[i] == endWord) e = i;
        for (int j = i+1; j < n; ++j) {
          if (diff_one(wordList[i], wordList[j])) {
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
      if (e == -1) return 0;
      std::fill(dist, dist+mxn, 0);
      std::queue<int> q;
      q.push(start);
      dist[start] = 1;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
          if (dist[v] == 0) {
            q.push(v);
            dist[v] = dist[u] + 1;
          }
        }
      }
      return dist[e];
    }
};

// no O(n^2) preprocessing, much faster overall O(n*L*26)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
      if (dict.find(endWord) == dict.end() || beginWord == endWord) return 0;
      int res = 0;
      std::queue<std::string> q;
      q.push(beginWord);
      while (!q.empty()) {
        res++;
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
          std::string u = q.front(); q.pop();
          if (u == endWord) return res;
          for (int j = 0; j < (int)u.size(); ++j) {
            char original = u[j];
            for (char c = 'a'; c <= 'z'; ++c) {
              if (c == original) continue;
              u[j] = c;
              if (dict.find(u) != dict.end()) {
                q.push(u);
                dict.erase(u);
              }
            }
            u[j] = original;
          }
        }
      }
      return 0;
    }
};
