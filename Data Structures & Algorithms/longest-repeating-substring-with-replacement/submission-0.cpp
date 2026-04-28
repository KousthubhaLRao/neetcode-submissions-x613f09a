class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0;
        int n = s.length();
        unordered_map<char,int> freq;
        int l = 0, maxlen = 0;

        for(int r = 0; r < n; r++)
        {
            freq[s[r]]++;
            maxf = max(maxf, freq[s[r]]);

            //window is valid as long as (window size - frequency of most frequent char is <= k)
            // i.e number of replacements (w-f) should not exceed k
            if((r-l+1) - maxf > k)
            {
                freq[s[l]]--;
                l++;
            }
            maxlen = r-l+1;
        }
        return maxlen;
    }
};
