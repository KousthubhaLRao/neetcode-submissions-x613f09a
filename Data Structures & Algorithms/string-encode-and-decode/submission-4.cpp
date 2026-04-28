class Solution {
public:

    string encode(vector<string>& strs) {
        string code;
        for(string &s : strs)
        {
            code += to_string(s.size()) + '#' + s;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i,j-i));
            i = j+1;

            res.push_back(s.substr(i,len));
            i+=len;
        }
        return res;
    }
};
