class FreqStack {
public:
    unordered_map<int, stack<int>> stacks; //mapping frequencies to stacks, cus why not? 
    unordered_map<int,int> mp;             //example : stack of freq 1 = {4, 5, 7}.
                                           // stack of freq 2 = {5, 7} and so on.
    //Ah but mp is a normal value -> frequency mapping.
    
    int max_freq = 0;

    FreqStack() {}
    
    void push(int val) {
        mp[val]++;
        stacks[mp[val]].push(val);
        max_freq = max(max_freq, mp[val]);
    }
    
    int pop() {
        int n = stacks[max_freq].top();
        stacks[max_freq].pop();
        mp[n]--;

        if(stacks[max_freq].empty()) max_freq--;

        return n;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */