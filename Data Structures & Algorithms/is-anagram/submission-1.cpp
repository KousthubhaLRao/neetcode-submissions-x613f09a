class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f1(26,0), f2(26,0);
        for(auto c : s) f1[c-'a']++;
        for(auto c : t) f2[c-'a']++;

        if(f1 == f2) return true;
        return false;
    }
};



