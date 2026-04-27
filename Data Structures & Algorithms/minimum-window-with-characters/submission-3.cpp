class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length() or !t.length()) return "";

        unordered_map<char,int> freq_t;
        for(char x : t) freq_t[x]++;

        pair<int,int> res = {-1,-1};
        int res_len = INT_MAX; 
        unordered_map<char,int> win;
        int have = 0; //how many characters currently meet the required count
        int need = freq_t.size(); //how many distinct characters we need to match. (at least)

        int n = s.length();
        int i = 0, j = 0;

        while(j < n)
        {
            char c = s[j];
            win[c]++;
            
            if(freq_t.count(c) && win[c] == freq_t[c]) {
                have++;
            }
            while(have == need)
            {
                if((j-i+1) < res_len)
                {
                    res_len = j-i+1;
                    res = {i, j};
                }

                win[s[i]]--;
                if(freq_t[s[i]] and win[s[i]] < freq_t[s[i]]) have--;
                i++;
            }
            j++;
        }
        return (res_len == INT_MAX ? "" : s.substr(res.first, res_len));
    }
};
