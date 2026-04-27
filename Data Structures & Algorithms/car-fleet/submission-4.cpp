class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> v;
        stack<double> stak;

        for(int i = 0; i < n; i++)
        {
            v.push_back({position[i], speed[i]});
        }

        sort(v.rbegin(), v.rend()); //sorts the vector of pairs in descending order on the first element. If clash, second element.

        for(int i = 0; i < n; i++)
        {
            double time = (double) (target - v[i].first) / v[i].second;

            if(!stak.empty() and time <= stak.top()) continue;

            stak.push(time);
        }

        return stak.size();
    }
};
