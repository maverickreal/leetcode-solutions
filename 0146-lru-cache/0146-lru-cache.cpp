class LRUCache {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

ll sz;
list<pi>l;
vi(list<pi>::iterator)ump;
LRUCache(int capacity) {
    sz=capacity;
    ump.assign(10001, end(l));
}

int get(int key) {
    if(ump[key]==end(l)){
        return -1;
    }
    const auto [k, v]=*ump[key];
    l.erase(ump[key]);
    l.pb({k, v});
    auto itr=l.end();
    --itr;
    ump[key]=itr;
    return v;
}

void put(int key, int value) {
    if(ump[key]!=end(l)){
        l.erase(ump[key]);
    }
    l.pb({key, value});
    auto itr=end(l);
    --itr;
    ump[key]=itr;
    if(l.size()==sz+1){
        const auto [k, v]=l.front();
        l.pop_front();
        ump[k]=end(l);
    }
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */