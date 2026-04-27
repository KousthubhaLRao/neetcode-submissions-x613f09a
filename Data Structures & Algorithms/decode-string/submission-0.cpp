class Solution {
public:
    string decodeString(string s) {
        stack<string> stak; 
        stack<int> numstack;
        string res = "";

        int num = 0;
        for(auto x : s)
        {

            if(isdigit(x))
            {
                num = num*10 + (x - '0');
            }

            else if(x == '[')
            {
                numstack.push(num);
                num = 0;
                stak.push("[");
            }
            else if(x == ']')
            {
                string part = "";
                while(stak.top() != "[")
                {
                    part = stak.top() + part;
                    stak.pop();
                }
                stak.pop();
                int n = numstack.top(); numstack.pop();
                string p = "";
                for(int i = 0; i < n; i++)
                {
                    p += part;
                }

                stak.push(p);
            }
            else stak.push(string(1, x));
        }
        while(!stak.empty())
        {
            res = stak.top() + res;
            stak.pop();
        }
        return res;
    }
};