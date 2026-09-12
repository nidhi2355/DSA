class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>> :: iterator> cachemap;

    LRUCache(int capacity) {
        cap= capacity;
    }
    
    int get(int key) {
        if(cachemap.find(key)== cachemap.end()) return -1;

        cache.splice(cache.begin(), cache, cachemap[key]);
        return cachemap[key]->second;
    }
    
    void put(int key, int value) {
        if(cachemap.find(key) != cachemap.end()){
            cache.splice(cache.begin(), cache, cachemap[key]);
            cachemap[key]->second= value;
        }
        else{
            if(cache.size()==cap){
                cachemap.erase(cache.back().first);
                cache.pop_back();
            }
            
            cache.push_front({key, value});
            cachemap[key]= cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */