class LRUCache {
public:
    int cap;
    unordered_map<int, int> cache; //key = key, value = value
    vector<int> keys;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {  
        if (cache.find(key) != cache.end()) {
            keys.push_back(key);
            return cache[key];
            
        } 
        return -1;
    }
    
    void put(int key, int value) {
        cache[key] = value;
        keys.push_back(key);
        if (cache.size() > cap) {
            //remove the least recently used key
            for (int i : keys) cout << i << " ";
            cout << endl;
            unordered_map<int, int> tally;
            for (int i = keys.size()-1; i >= 0; i--) {
                tally[keys[i]] = i;
                if (tally.size() > cap) {
                    cache.erase(keys[i]);
                    break;
                }
            }
        }
    }
};
