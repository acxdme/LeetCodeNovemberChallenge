/*
Time complexity : O(N)
Space complexity : O(1)
My approach : minimum of even count and odd position count.
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        if (n==0 or n==1) return 0;
        int count=0,count1=0;
        for(int i=0;i<n;i++)
        {
            if(position[i]%2 == 0 ) count++;
            else count1++;
        }
        
        return min(count,count1);
    }
};
