/*
Time complexity : O(N)
Space complexity : O(1) ignoring recursion stack.
My appraoch : the maximum will be the sum of the node with its grandchildren or sum of children nodes.

*/
class Solution {
public:
    
    unordered_map<TreeNode*,int> mp;
    // int sum =0;
     int  helperRobber(TreeNode* root)
    {
        if(root == NULL) return 0;
        if(mp.count(root)) return mp[root];
        int sum =0;
         if(root->left)
             sum += helperRobber(root->left->left) + helperRobber(root->left->right);
         if(root->right)
              sum += helperRobber(root->right->right) + helperRobber(root->right->left);
         
         return mp[root] = max(root->val+ sum , helperRobber(root->left)+ helperRobber(root->right));
    }
    int rob(TreeNode* root) {
        if(root == NULL )
            return 0;
        if( root->left == NULL and root->right == NULL)
            return root->val;
         int ans =0;
         ans = helperRobber(root);
        
        return ans;
        
    }
};
