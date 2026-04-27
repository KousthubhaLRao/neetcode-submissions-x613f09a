class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        for(int i = 0; i < q1.size()-1; i++)
        {
            int x = q1.front(); q1.pop();
            q1.push(x);
        }
        int popped = q1.front();
        q1.pop();
        return popped;
    }
    
    int top() {
        for(int i = 0; i < q1.size()-1; i++)
        {
            int x = q1.front(); q1.pop();
            q1.push(x);
        }
        int topp = q1.front();
        q1.pop();
        q1.push(topp);
        return topp;
    }
    
    bool empty() {
        return q1.empty();
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