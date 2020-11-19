/*
Time complexity : O(N)
Space complexity : O(1)
My approach : Sort the given input on the bases of the starting time, now check if the end point of ith interval is greater or equal to i+1 th interval(overlapping condition)
              then merge these intervals, else push the it result .
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        if(n==0) return  res;
        sort(intervals.begin(),intervals.end());   //sorting to be done if no info about order is given
        vector<int> temp;
        temp = intervals[0];
        for(int i=1;i<n;i++)
        {
            if(temp[1] >= intervals[i][0] )
            {
                temp[1] = max(temp[1],intervals[i][1]);
            }
            else
            {
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        res.push_back(temp);
        
        return res;
            
        
    }
};
