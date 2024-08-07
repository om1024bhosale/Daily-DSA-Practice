/*
link -> https://leetcode.com/problems/binary-tree-right-side-view/description/

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

class Solution {
public:
 
    void helper(TreeNode* root, vector<int>& ans,int level)
    {
        if(!root) return;
        
       if(ans.size()==level) ans.push_back(root->val);
        
        helper(root->right,ans,level+1);
        helper(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        helper(root,ans,0);
        return ans;
    }
};
