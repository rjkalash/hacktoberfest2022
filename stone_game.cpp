/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.Accepted Solution
Problem Link:
https://leetcode.com/contest/weekly-contest-311/problems/reverse-odd-levels-of-binary-tree/

Please merge this pull request under hacktoberfest tag
*/

class Solution {
public:
    int dp[501][501];
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return fun(piles, 0, piles.size() - 1) > 0;
    }
    
    int fun(vector<int> &v, int i, int j) {
        if(i == j) return v[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int x = v[i] - fun(v, i + 1, j);
        int y = v[j] - fun(v, i, j - 1);
        
        return dp[i][j] = max(x, y);
    }
};
