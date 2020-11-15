/*
Time complexity :  O(N)
Space complexity : O(1), ignoring space used in recursion.
My appraoch : traverse bst and find the valid nodes and add those values.
*/

class Solution {
public:
    
    int count = 0;
    void helper(TreeNode* root , int low ,int high)
    {
        if(root == NULL) return;
        if(root->val >= low and root->val <= high)
            count+=root->val;
        helper(root->left,low,high);
        helper(root->right,low,high);
        
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        helper(root,low,high);
        
        return count;
    }
};
