class MinStack {
public:
    list<int>st, mn;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(mn.empty()){
            mn.push_back(val);
        } else{
            mn.push_back(min(mn.back(), val));
        }
    }
    
    void pop() {
        mn.pop_back();
        st.pop_back();
    }
    
    int top() {
       return st.back(); 
    }
    
    int getMin() {
     return mn.back();   
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