class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int i = 0, j = 0;
        for(char x : s1)
        {
            freq1[x-'a']++;
        }

        while(j < s2.size())
        {
            freq2[s2[j] - 'a']++;

            if(j-i+1 > s1.length())
            {
                freq2[s2[i] - 'a']--;
                i++;
            }

            if(j-i+1 == s1.length())
            {
                if(freq1 == freq2) return true;
            }
            j++;
        }
        return false;
    }
};
