/*
Time complexity : O(N)
Space complexity : O(N) , for using queue
My approach : perform bfs traversal and connect the next pointers.
*/
class Solution {
public:
    void bfs_helper(Node* root )
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node *temp = q.front();
                q.pop();
                if(i==n-1)
                    temp->next =NULL;
                else
                    temp->next = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
    }
    Node* connect(Node* root) 
    {
        if(root == NULL) return root;
         bfs_helper(root);
        
        return root;
        
    }
};
