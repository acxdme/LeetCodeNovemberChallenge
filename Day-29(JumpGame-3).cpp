/*
 Time complexity : O(N)
 Space complexity : O(N)
 My approach : Using dfs to find the from start does a valid position exists or not
 */
 
 class Solution {
public:
    
     void helper(vector<int>& arr ,int pos, vector<bool>& visited,bool& res)
    {
        
        
        if(pos<0 or pos>= arr.size() ) return ;
        if(visited[pos]== true ) return ;
         visited[pos] = true;
        
        if(arr[pos] == 0 )
        {
            res = true;
            return ;
        }
        
        helper(arr,pos+arr[pos],visited,res);
        helper(arr,pos-arr[pos],visited,res);
        
       return ;
    }
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        
        if(n ==1 and arr[0] == 0 ) return true;
         int flag = false;
        for(int i=0;i<n;i++)
        {  if(arr[i] == 0 )
            {
                flag =true;
                break;
            }
        }
        if(flag == false) return false;
        vector<bool> visited(n,false);
        
        bool res = false;
        helper(arr,start,visited,res);
        
        return res;
        
            
    }
};
