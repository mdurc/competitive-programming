class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> m_keys;
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        m_keys[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& vec = m_keys[key];
        int i = 0;
        int j = vec.size();
        // find largest vec[].first value that is less than timestamp arg
        string ret = "";
        while (i<j){
            int mid = i + (j-i)/2;
            if (vec[mid].first == timestamp){
                return vec[mid].second;
            }else if (vec[mid].first < timestamp){
                ret = vec[mid].second;
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        return ret;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
