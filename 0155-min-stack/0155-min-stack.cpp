class MinStack {
public:
    list<int>l;
    MinStack() {
        
    }
    
    void push(int val) {
        l.push_back(val);
    }
    
    void pop() {
        l.pop_back();
    }
    
    int top() {
        return l.back();
    }
    
    int getMin() {
        int mn = INT_MAX;
        for(int it : l){
            mn = min(mn, it);
        }
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */