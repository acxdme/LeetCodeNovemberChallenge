/*
Time complexity :O(N)
Space complexity : O(1) , ignoring recursion stack.
My approach : if its a leaf return the root's data and modify it to 0 before returning, if root is null return 0 , for non leaf nodes recursively calculated l and r 
              root's data becomes abs(l-r) but the value returned is root->data + l + r.
*/

class Solution {
  int res = 0;  
    int helper(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        if(root->left == NULL and root->right== NULL)
        {
            int temp = root->val;
            root->val = 0;
            return temp;
        }
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        int temp = root->val + l + r;
        root->val = abs(l-r);
        res += root->val;
        
        
        return temp; 
    }
public:
    int findTilt(TreeNode* root) 
    {
       if(root == NULL ) return 0;
       helper(root); 
       return res;
    }
};
