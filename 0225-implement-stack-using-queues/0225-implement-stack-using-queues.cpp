class MyStack {
public:
    queue<int>q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int>*emp, *filled;
        if(q1.empty()){
            emp=&q1, filled=&q2;
        } else{
            emp=&q2, filled=&q1;
        }
        emp->push(x);
        while(!filled->empty()){
            emp->push(filled->front());
            filled->pop();
        }
    }
    
    int pop() {
        int ans;
        if(!q1.empty()){
            ans = q1.front();
            q1.pop();
        }
        if(!q2.empty()){
            ans = q2.front();
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        return (q1.empty() ? q2.front() : q1.front());
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */