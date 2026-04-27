class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> stak;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                int a = stak.top(); stak.pop();
                int b = stak.top(); stak.pop();

                res = (a+b);
                stak.push(res);
            }
            else if(tokens[i] == "*")
            {
                int a = stak.top(); stak.pop();
                int b = stak.top(); stak.pop();
                res = a*b;
                stak.push(res);
            }
            else if(tokens[i] == "-")
            {
                int a = stak.top(); stak.pop();
                int b = stak.top(); stak.pop();
                res = b-a;
                stak.push(res);
            }
            else if(tokens[i] == "/")
            {
                int a = stak.top(); stak.pop();
                int b = stak.top(); stak.pop();
                res = b/a;
                stak.push(res);
            }
            else //it's a number
            {
                stak.push(stoi(tokens[i]));
                res = stak.top();
            }
        }
        return res;
    }
};
