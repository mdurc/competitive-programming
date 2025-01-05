class LRUCache {
private:
    // map <key, {value, location in list}>
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    // using a list due to many deletions and insertions to
    // move elements to the front/back, etc.

    // holding all the keys
    list<int> used; // LRU will be the front, MRU will be back
    int m_capacity;
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // otherwise, it should become the "most" recently used
        used.erase(cache[key].second);
        used.push_back(key);
        cache[key].second = --used.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            // dont need to account for overflow of capacity
            used.erase(cache[key].second); // remove it so it can be moved to MRU
        }else if (used.size()+1 > m_capacity){
            cache.erase(used.front());
            used.pop_front();
        }
        used.push_back(key);
        cache[key] = {value, --used.end()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
