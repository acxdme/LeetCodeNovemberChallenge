/*
Time complexity : O(N)
Space complexity : O(N)
My approach : Using dequeue to maintain the k the maximum in a window.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if(k ==1) return nums;
        int n = nums.size();
        deque<int> dq;
        int i;
        vector<int> res;
        for(i=0;i<k;i++)
        {
            while(dq.size() > 0 and nums[dq.back()] < nums[i])  dq.pop_back();
            
            dq.push_back(i);     
        }
        
        for( ;i<n;i++)
        {
            res.push_back(nums[dq.front()]);
            while( dq.size() > 0 and  dq.front() <= i-k )
                dq.pop_front();
            while(dq.size() > 0 and   nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
        
    }
};
