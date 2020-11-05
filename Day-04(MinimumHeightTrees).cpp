/*
Time complexity : O(N^2)
Space complexity : O(N)
Approach - 1 : For every node as potential root for a tree, perform a bfs to find the height of the tree, store the  height along with its root in a map and finally return the
              roots(maximum two in number) who possess the minimum height.
*/

class Solution {
public:
    
    int bfs(int s,vector<int> adjList[] , vector<bool>& visited)
    {

        int count =0;
        queue<pair<int,int>> q;
        q.push({0 , s});
        visited[s] = true;
        int ans = 0;
        while(!q.empty())
        {
            auto temp = q.front();
            ans = max(ans , temp.first);
            q.pop();
            for(int i=0;i<adjList[temp.second].size();i++)
            {
                if(!visited[adjList[temp.second][i]]) {
                    q.push({temp.first + 1 , adjList[temp.second][i]});
                    visited[adjList[temp.second][i]] = true;
                }
            }
        }
        //cout<<ans<<endl;
        return ans;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) //main function
    {
         vector<int> result; //result vector
        int esize = edges.size();
        if(n==1)
            return {0};
        
         vector<int> adjList[n];  //adjacency list
        
        for(int i=0;i<esize;i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
        
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n,false);
        
        unordered_map<int,int> m;  // map<Root,height>
        for(int i=0;i<n;i++)
        {
            vector<bool> visited(n,false);  //maintaing visited 
            int h = bfs(i,adjList,visited);
             m[i]= h;
        }
        
        int mn = INT_MAX;
        for(auto it : m)
        {
            if(it.second < mn )
                mn = it.second;
        }
        
        cout<<mn<<endl;
       
        for(auto it : m)
        {
            if(it.second == mn )
                result.push_back(it.first);
        }
        
        return result;
        
    }
};
