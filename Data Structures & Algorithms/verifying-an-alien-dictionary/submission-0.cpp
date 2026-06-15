class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++)
            mp[order[i]] = i;

        for(int i = 0; i < words.size()-1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];
            int j = 0;

            for(; j < w1.size(); j++)
            {
                if(j == w2.size()) return false; //this is only possible if the first word w1 is longer than w2, which is an invalid lexicographic order.
                if(w1[j] != w2[j])
                {
                    if(mp[w1[j]] > mp[w2[j]]) return false;

                    break; //cus that means the current two words are in correct order and need not be checked further?
                }
            }
        }
        return true;
    }
};