class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        stack<int> rec;
        int n = operations.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(operations[i] == "+")
            {
                int a = rec.top(); rec.pop();
                int b = rec.top(); rec.pop();
                int plus = a + b;
                rec.push(b);
                rec.push(a);
                rec.push(plus);
                sum += plus;
            }
            else if(operations[i] == "C")
            {
                int c = rec.top(); rec.pop();
                sum -= c;
            }
            else if(operations[i] == "D")
            {
                rec.push(2*rec.top());
                sum += rec.top();
            }
            else
            {
                int val = stoi(operations[i]);
                rec.push(val);
                sum += val;
            }
        }
        return sum;
    }
};