class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n + 1, 0);

        for (auto& t : trust) {
            delta[t[0]]--;
            delta[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (delta[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

//well my solution used hashmaps and tracked the actual people that trust and are trusted, but that's not really necessary.
//we just need to track the NUMBER of people that trust and are trusted. 
//this optimal solution does that and even goes a step beyond by storing only the difference between the indegree and outdegree.
//only the town judge will have a delta (difference between indegee and outdegree) of n-1, cus (n-1 - 0 = n-1).