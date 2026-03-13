#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        int z = edges.size();
        for (int i = 0; i<z; ++i){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // for using pair<int, double> comparing the second one as a max heap
        //struct cmp{
        //    bool operator()(const pair<int, double>& a, const pair<int,double>& b){
        //        return a.second < b.second;
        //    }
        //};
        //priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> pq;

        // max heap with default pair comparison: compares .first then if equal, compares .second
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        unordered_set<int> seen;
        while(!pq.empty()){
            pair<double, int> node = pq.top();
            pq.pop();
            if (seen.find(node.second)!=seen.end()) continue;
            seen.insert(node.second);
            if (node.second == end_node){
                return node.first;
            }
            for (const pair<int, double>& p : adj[node.second]){
                if(seen.find(p.first)!=seen.end()) continue;
                pq.push({p.second*node.first, p.first});
            }
        }
        return 0;
    }
};
