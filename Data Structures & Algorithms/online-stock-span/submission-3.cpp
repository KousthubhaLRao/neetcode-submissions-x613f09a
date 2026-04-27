class StockSpanner {
public:
    StockSpanner() {}
    stack<pair<int, int>> stack1;

    int next(int price) {
        //stack1.push(price);
        int span = 1;
        
        while(!stack1.empty() and stack1.top().first <= price)
        {
            int s = stack1.top().second; stack1.pop();
            span += s;
        }
        stack1.push({price, span});
        return span;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */