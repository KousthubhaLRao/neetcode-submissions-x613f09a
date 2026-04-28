class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for(auto x : s)
        {
            if(mp.count(x)) stack.push(x);
            else
            {
                if(!stack.empty() and mp[stack.top()] == x) stack.pop();
                else return false;
            }
        }
        return stack.empty();
    }
};
