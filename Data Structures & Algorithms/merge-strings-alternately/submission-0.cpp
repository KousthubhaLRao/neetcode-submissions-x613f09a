class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i = 0, j = 0, k = 0;
        while(i < word1.length() and j < word2.length())
        {
            if(k%2 == 0)
            {
                s.push_back(word1[i]);
                k++;
                i++;
            }
            else
            {
                s.push_back(word2[j]);
                k++;
                j++;
            }
        }
        if(i == word1.length())
        {
            while(j < word2.length())
            {
                s.push_back(word2[j]);
                k++;
                j++;
            }
        }
        else
        {
            while(i < word1.length())
            {
                s.push_back(word1[i]);
                k++;
                i++;
            }
        }
        return s;
    }
};