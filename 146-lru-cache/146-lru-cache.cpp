class LRUCache {
    typedef pair<int,int> pi;
public:
    int cap;
    list<pi>l;
    unordered_map<int, list<pi>::iterator>ump;
    LRUCache(int c) {
        cap=c;
    }
    
    int get(int key) {
        if(ump.find(key)==ump.end()){
            return -1;
        }
        int ans=ump[key]->second;
        l.erase(ump[key]);
        l.push_back({key, ans});
        ump[key]=--l.end();
        return ans;
    }
    
    void put(int key, int val) {
        if(ump.size()<cap || ump.find(key)!=ump.end()){
            if(ump.find(key)!=ump.end()){
                l.erase(ump[key]);
            }
            l.push_back({key, val});
            ump[key]=--l.end();
        }
        else{
            ump.erase(l.front().first);
            l.pop_front();
            return put(key, val);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */