class Solution {
public:
    static int cmp(vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
    }
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<vector<int>> v;
        v.push_back({logs[0][1], logs[0][0]});
        int last = logs[0][1];
        for(int i = 1; i < logs.size(); i++) {
            v.push_back({logs[i][1] - last, logs[i][0]});
            last = logs[i][1];
        }
        sort(v.begin(), v.end(),cmp);
        
        return v[0][1];
    }
};
