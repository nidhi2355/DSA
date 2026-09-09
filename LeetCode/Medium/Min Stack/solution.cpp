class MinStack {
public:
    stack<int> st1;
    stack<int> st2;

    MinStack() {
        
    }
    
    void push(int value) {
        st1.push(value);
        if(st2.empty() or st2.top()>= value) st2.push(value);
    }
    
    void pop() {
        int val= st1.top();
        st1.pop();
        if(st2.top()==val) st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */