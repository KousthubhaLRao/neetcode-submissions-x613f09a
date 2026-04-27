class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0;
        int j = n-1;
        int res = 0;

        while(i <= j)
        {
            // if(people[j] == limit)
            // {
            //     j--;
            //     res++;
            //     continue;
            // }
            if(people[i]+people[j] <= limit)
            {
                i++;
                j--;
                res++;
                continue;
            }
            else //if(people[i]+people[j] > limit) or if(people[j] == limit)
            {
                j--;
                res++;
                continue;
            }
            // if(i == j)
            // {
            //     i++;
            //     j--;
            //     res++;
            // }
        }
        return res;
    }
};