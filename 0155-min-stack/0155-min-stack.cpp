class MinStack {
public:
    list<long>l;
    long mn;
    MinStack() {
        
    }
    
    void push(long val) {
        if(l.empty()){
            l.push_back(val);
            mn = val;
            return;
        }
        if(val>=mn){
            l.push_back(val);
        } else{
            l.push_back(2*val-mn);
            mn=val;
        }
    }
    
    void pop() {
        if(l.back()<mn){
            mn = 2*mn - l.back();
        }
        l.pop_back();
    }
    
    int top() {
        return max(l.back(), mn);
    }
    
    int getMin() {
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