// Segment tree--
struct SGT {
  int sz;
  vector<int> tree;
  SGT(int n) {
    sz = 1;
    while (sz < n) sz <<= 1;
    tree.assign(2 * sz, 0);
  }
  void change(int idx, int val) {
    tree[sz + idx] += val;
    for (int i = (sz + idx) / 2; i >= 1; i /= 2) {
      tree[i] = tree[2*i] + tree[2*i+1];
    }
  }
  int query() {
    if (tree[1] == 0) return -1;
    int i = 1;
    while (i < sz) {
      if (tree[2*i] > 0) {
        i = 2*i;
      } else {
        i = 2*i+1;
      }
    }
    return i-sz;
  }
};
class Solution {
    struct Event {
      int pos, type, param;
      bool operator<(const Event& other) const {
        if (pos != other.pos) return pos < other.pos;
        return type < other.type;
      }
    };
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
      std::vector<int> sizes;
      for (std::vector<int>& i : intervals) {
        sizes.push_back(i[1]-i[0]+1);
      }
      std::sort(sizes.begin(), sizes.end());
      sizes.erase(std::unique(sizes.begin(), sizes.end()), sizes.end());
      auto rank = [&](int s) {
        return lower_bound(sizes.begin(), sizes.end(), s) - sizes.begin();
      };
      std::vector<Event> events;
      for (std::vector<int>& i : intervals) {
        int len = i[1]-i[0]+1;
        events.push_back({i[0], 1, len});
        events.push_back({i[1]+1, 2, len});
      }
      for (int i = 0; i < queries.size(); ++i) {
        events.push_back({queries[i], 3, i});
      }
      std::sort(events.begin(), events.end());
      SGT sgt(sizes.size());
      std::vector<int> res(queries.size());
      for (Event& e : events) {
        if (e.type == 1) {
          sgt.change(rank(e.param), 1);
        } else if (e.type == 2) {
          sgt.change(rank(e.param), -1);
        } else {
          int rank = sgt.query();
          if (rank == -1) res[e.param] = -1;
          else res[e.param] = sizes[rank];
        }
      }
      return res;
    }
};
// ---

// lowerbound search on the sorted interval lengths, for each query
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
      std::sort(intervals.begin(), intervals.end(), [&](const std::vector<int>& a, const std::vector<int>& b) {
          return a[1]-a[0] < b[1]-b[0];
          });
      int n = (int)queries.size();
      std::vector<int> res(n, -1);
      std::set<std::pair<int, int>> s;
      for(int i = 0; i < n; ++i) {
        s.insert({queries[i], i});
      }
      for(int i = 0; i < (int)intervals.size(); ++i) {
        int l = intervals[i][0], r = intervals[i][1];
        auto it = s.lower_bound({l, 0});
        while(it != s.end() && it->first <= r) {
          res[it->second] = r-l+1;
          it = s.erase(it);
        }
        if (s.empty()) break;
      }
      return res;
    }
};

// event linesweep
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
      std::vector<std::vector<int>> events;
      for (int i = 0; i < intervals.size(); i++) {
        events.push_back({intervals[i][0], 0, intervals[i][1]-intervals[i][0]+1});
        events.push_back({intervals[i][1], 2, intervals[i][1]-intervals[i][0]+1});
      }
      for (int i = 0; i < queries.size(); i++) {
        events.push_back({queries[i], 1, i});
      }
      std::sort(events.begin(), events.end());
      std::multiset<int> sizes;
      std::vector<int> ans(queries.size(), -1);
      for (auto event : events) {
        if (event[1] == 0) {
          sizes.insert(event[2]);
        } else if (event[1] == 1) {
          if (sizes.size() > 0) {
            ans[event[2]] = (*sizes.begin());
          }
        } else {
          sizes.erase(sizes.lower_bound(event[2]));
        }
      }
      return ans;
    }
};
