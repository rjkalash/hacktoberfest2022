/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.
*/

class Solution {
public:
    int dp[100];
    int integerBreak(int n) {
        memset(dp, -1, sizeof dp);
        int mx = fun(1, n, 0, 2);
        return mx;
    }
    
    int fun(int p, int n, int c, int k) {
        if(n == 0) {
            if(c >= k) return p;
            return 0;
        }
        if(n < 0) return 0;
        if(dp[n] != -1) return p * dp[n];
        int mx = 0;
        for(int i = 1; i <= n; i++)
            mx = max(mx, fun(p * i, n - i, c + 1,  k));
        return dp[n] = mx;
    }
};
