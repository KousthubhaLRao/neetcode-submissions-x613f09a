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

// unordered_map<char, int> f1, f2;
// for(auto x : s) f1[x]++;
// for(auto x : t) f2[x]++;

