/*
Time complexity : O(N)
Space complexity : O(1)
My approach :
*/

class Solution {
public:
    int maxPower(string s) 
    {
        int count =0,answer =0;
        int n = s.size();
        if(n==0) return count;
        char c = s[0];
        count++;
        
        for(int i=1;i<n;i++)
        {
            if(c == s[i]) count++;
            else
            {
                answer = max(count,answer);
                count =1;
                c= s[i]; 
            }
        }
        
        return max(answer,count);
        
    }
};
