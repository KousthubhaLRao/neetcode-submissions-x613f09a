class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++)
        {
            int t = temperatures[i];
            while(!stack.empty() and t > stack.top().first)
            {
                int top = stack.top().second; stack.pop();
                res[top] = i-top;
            }
            stack.push({t, i});
        }
        return res;
    }
};
