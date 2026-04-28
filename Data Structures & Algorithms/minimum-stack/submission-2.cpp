class MinStack {
public:
    MinStack() {}
    stack<int> stak, extra;

    void push(int val) {
        if(extra.empty()) extra.push(INT_MAX);
        
        stak.push(val);
        extra.push(min(extra.top(), val));
    }
    
    void pop() {
        stak.pop();
        extra.pop();
    }
    
    int top() {
        return stak.top();
    }
    
    int getMin() {
        return extra.top();
    }
};
