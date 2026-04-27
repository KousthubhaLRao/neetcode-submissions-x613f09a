class StockSpanner {
public:
    StockSpanner() {}
    stack<int> stack1, stack2;

    int next(int price) {
        stack1.push(price);
        int count = 0;
        
        while(!stack1.empty() and stack1.top() <= price)
        {
            stack2.push(stack1.top()); stack1.pop();
            count++;
        }
        while(!stack2.empty())
        {
            stack1.push(stack2.top()); stack2.pop();
        }
        return count;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */