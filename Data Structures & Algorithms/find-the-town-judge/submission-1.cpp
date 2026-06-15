class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> mp1, mp2;


        for(int i = 0; i < trust.size(); i++)
        {
            mp1[trust[i][1]].emplace_back(trust[i][0]);  //track all people WHO TRUST a particular person. kinda like a directed graph
            mp2[trust[i][0]].emplace_back(trust[i][1]);  //track all people TRUSTED BY a particular person. 
        }

        for(int i = 1; i <= n; i++)
        {
            if(!mp2.count(i))  //first confition : the town judge trusts nobody. So their outdegree count must be 0.
            {
                if(mp1[i].size() == n-1) //second condition : everybody trusts the town judge
                {
                    return i;
                }
            }
        }

        return -1;
    }
};