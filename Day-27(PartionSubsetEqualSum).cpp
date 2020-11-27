/*
Time complexity :  O(n^2)
Space complexity : O(N^2)
My approach : using  subset sum as subroutine for this problem.
*/
class Solution {
public:
    
    bool subsetSum(vector<int>& nums, int k, int size)
    {
        bool dp[size+1][k+1];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<=size;i++)
            dp[i][0] = true;
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = ( dp[i-1][j] or dp[i-1][j-nums[i-1]]);
            }
        }
                                
         return dp[size][k];
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0 or n==1 ) return false;
        int sum =0;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum % 2 != 0 ) return false;
        
        bool res;
        
        res = subsetSum(nums,sum/2,n);
        
        return res;
        
    }
};

