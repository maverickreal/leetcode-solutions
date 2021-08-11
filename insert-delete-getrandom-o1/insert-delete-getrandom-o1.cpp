class RandomizedSet {
public:
    unordered_set<int>ust;
    vector<int>v;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ust.find(val)==ust.end()){
            ust.insert(val);
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(ust.find(val)!=ust.end()){
            ust.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r=rand()%v.size();
        while(ust.find(v[r])==ust.end()){
            v.erase(v.begin()+r);
            //srand(time(NULL));
            r=rand()%v.size();
        }
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */