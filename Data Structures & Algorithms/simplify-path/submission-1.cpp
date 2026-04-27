class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stak;
        stringstream ss(path);
        string part;

        while(getline(ss, part, '/'))
        {
            //if(part.empty()) continue;
            if(!stak.empty() and part == ".." ) stak.pop();
            else if(!part.empty() and part != "." and part != "..") stak.push(part);
        }

        string res = "";

        while(!stak.empty())
        {
            res = "/" + stak.top() + res; stak.pop();
        }

        return res.empty() ? "/" : res;
    }
};