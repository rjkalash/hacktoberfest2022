class Solution {
public:
    static bool cmp(pair<int,string> &a,pair<int,string> &b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words)
            mp[it]+=1;
        vector<pair<int,string>> vc;
        for(auto it:mp)
            vc.push_back({it.second,it.first});
        sort(vc.begin(),vc.end(),cmp);
        int n=vc.size();
        words.clear();
        int c=1;
        while(c<=k)
        {
            words.push_back(vc[n-c].second);
            c++;
        }
        return words;
    }
};
