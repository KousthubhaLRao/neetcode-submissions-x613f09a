class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> win;
        int maxlen = 0;
        int i = 0, j = 0;
        while(j < s.size())
        {
            while(win.count(s[j]))
            {
                win.erase(s[i]);
                i++;
            }
            win.insert(s[j]);
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen; // TO BE CONTINUED.
    }
};
