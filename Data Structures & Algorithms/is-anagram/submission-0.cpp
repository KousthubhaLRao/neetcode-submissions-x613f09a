class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> f1, f2;
        for(auto x : s) f1[x]++;
        for(auto x : t) f2[x]++;

        if(f1 == f2) return true;
        return false;
    }
};
