class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1 , 0);
        dp[0] = 1;
        
        for(int idx=1; idx<=n; idx++){
            
            if(idx >= 2) {     
                dp[idx] = dp[idx] | (dp[idx - 2] == 1 && (nums[idx-1] == nums[idx-2]) );
            }
        
            if(idx >= 3){
                dp[idx] = dp[idx] | (dp[idx - 3 ] == 1 && ((nums[idx - 1] == nums[idx - 2]) && (nums[idx -2] == nums[idx - 3])) );
            
            
                dp[idx] = dp[idx] | (dp[idx - 3 ] == 1 && ((nums[idx - 1] == nums[idx - 2] + 1) && (nums[idx -2] == nums[idx - 3] + 1 )) );
    
            }
        }
        return dp[n];
        
    }
    

};
