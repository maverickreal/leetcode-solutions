class MyHashSet {
public:
    /** Initialize your data structure here. */
    list<int>* l=new list<int>[100];
    MyHashSet() {
    }
    
    void add(int k) {
        l[k%100].push_back(k);
    }
    
    void remove(int k) {
        l[k%100].remove(k);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int k) {
        for(int i:l[k%100]){
            if(i==k)
                return true;
    }
        return false;
        }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */