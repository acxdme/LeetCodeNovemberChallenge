/*
Time complexity : O(n*n!)
Space complexity : O(N)
My approach :  recursively find the permutations using backtracking, store the permutation in a set to remove duplicates.
*/

class Solution {
public:
    
    void helper(vector<int>& nums,set<vector<int>>& res,int l ,int r)
    {
        if(l == r)
        {
            res.insert(nums);
            return;
        }
        else
        {
            for(int i=l;i<=r;i++)
            {
                swap(nums[i],nums[l]);
                helper(nums,res,l+1,r);
                swap(nums[i],nums[l]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        int n = nums.size();
         set<vector<int>> res;
        vector<vector<int>> result;
        if(n==0) return result;
        
        helper(nums,res,0,n-1);
        
        for(auto it : res)
        {
            result.push_back(it);
        }
        return result;
    }
};
