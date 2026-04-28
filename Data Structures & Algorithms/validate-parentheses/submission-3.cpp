class Solution {
public:
    bool isValid(string s) {
        stack<char> stak;
        int n = s.length();

        if(s[0] == ')' or s[0] == ']' or s[0] == '}') return false;

        for(auto x : s)
        {
            if(x == '(' or x == '[' or x == '{') stak.push(x);
            else if((x == ')' or x == ']' or x == '}') and stak.empty()) return false;
            else
            {
                char c = stak.top();
                if(c == '(' and x == ')') stak.pop();
                else if(c == '[' and x == ']') stak.pop();
                //if(c == '(' and x == ')')
                else if(c == '{' and x == '}') stak.pop();
                else return false;
            }
        }
        if(stak.empty()) return true;
        else return false;
    }
};
