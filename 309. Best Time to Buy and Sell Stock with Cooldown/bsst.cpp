class Solution {
public:
    int check(vector<int> &prices,int idx,bool buy,vector<vector<int>> &dp)
    {
        if(idx>=prices.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        int profit=0;
        if(buy==true) profit=max(-prices[idx]+check(prices,idx+1,false,dp),0+check(prices,idx+1,true,dp));
        else
         profit=max(+prices[idx]+check(prices,idx+2,true,dp),0+check(prices,idx+1,false,dp)); 
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return check(prices,0,true,dp);
    }
};
