class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      std::vector<std::vector<int>> adj(numCourses);
      std::vector<int> indegree(numCourses, 0);
      for (std::vector<int>& rec: prerequisites) {
        adj[rec[1]].push_back(rec[0]);
        indegree[rec[0]]++;
      }
      // see if topological sort exists, the graph must be acyclic
      std::queue<int> q;
      for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) q.push(i);
      }
      int seen = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        ++seen;
        for (int v: adj[u]) {
          if (--indegree[v] == 0) {
            q.push(v);
          }
        }
      }
      return seen == numCourses;
    }
};
