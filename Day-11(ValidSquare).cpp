/*
Time complexity : O(1)
Space complexity : O(1)
My approach : har point se sirf do unique distances hone chaiye aur koi bhi  point coincide nahi karna chaiye square ka.
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        unordered_set<int> t; 
         if(p1 == p2 or p1 ==p3 or p1 == p4 or p2 == p3 or p2 == p4 or p3== p4)
              return false;
        vector<pair<int,int> > v;  
        v.push_back({p1[0],p1[1]});
        v.push_back({p2[0],p2[1]});
        v.push_back({p3[0],p3[1]});
        v.push_back({p4[0],p4[1]});
        
        int n =4;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                int distance = pow(v[i].first-v[j].first,2) + pow(v[i].second-v[j].second,2);
                t.insert(distance);
            }
            if(t.size()!=2)
                return false;
        }
        
        return true;

    }
};
