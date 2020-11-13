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

//Just a variation of code , but clears a lot of things such as the re-swap can be done in backtracking part.

class Solution {
public:
    
    void helper(vector<int> nums,set<vector<int>>& res,int l ,int r)
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
//                 swap(nums[i],nums[l]);
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

// Method -2 ,Pruning the Unrequired branches caused by the duplicates in the given nums vector
// This is a more efficient method.
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

