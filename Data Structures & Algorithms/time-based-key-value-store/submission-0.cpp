class TimeMap {
public:
    TimeMap() {}
    unordered_map<string, vector<pair<string, int>>> mp;

    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";

        vector<pair<string, int>> arr = mp[key];
        int l = 0, r = arr.size() - 1, mid; 
        string res;

        while(l <= r)
        {
            mid = (l + r) / 2;
            if(arr[mid].second <= timestamp)
            {
                res = arr[mid].first;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};
