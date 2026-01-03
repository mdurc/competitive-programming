class Solution {
public:
    std::vector<int> getIds(const std::string& s) {
        std::vector<int> res;
        int n = (int)s.size();
        for (int i = 0; i < n;) {
            int r = i+2;
            while (r < n && !isspace(s[r])) ++r;
            res.push_back(stoi(s.substr(i+2, r-(i+2))));
            i = r+1;
        }
        return res;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        std::vector<int> res(numberOfUsers, 0);
        int all_cnt = 0;
        std::map<int,int> offline; // user -> time to free
        std::sort(events.begin(), events.end(), [&](auto& a, auto& b) {
            if (a[1] != b[1]) return stoi(a[1]) < stoi(b[1]); // Timestamp first
            return a[0] > b[0]; // "Offline" before "Message"
        });
        for (int i = 0; i < events.size(); ++i) {
            std::cout << events[i][0] << ", " << events[i][1] << "\n";
        }
        for (std::vector<std::string>& e: events) {
            if (e[0] == "OFFLINE") {
                int time = stoi(e[1]);
                int user = stoi(e[2]);
                offline[user] = time+60;
                continue;
            }
            int time = stoi(e[1]);
            if (e[2] == "ALL") {
                ++all_cnt;
            } else if (e[2] == "HERE") {
                for (int i = 0; i < numberOfUsers; ++i) {
                    auto itr = offline.find(i);
                    if (itr == offline.end() || (itr != offline.end() && itr->second <= time)) {
                        res[i]++;
                        if (itr != offline.end()) offline.erase(itr);
                    }
                }
            } else {
                for (int i: getIds(e[2])) {
                    res[i]++;
                }
            }
        }
        if (all_cnt > 0) {
            for (int& i: res) {
                i += all_cnt;
            }
        }
        return res;
    }
};
