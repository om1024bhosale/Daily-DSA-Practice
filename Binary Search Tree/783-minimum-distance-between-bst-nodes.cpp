/*
link -> https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/

class Solution {
public:
    void minimum(TreeNode* root, int &prev, int &ans)
    {
        if(!root) return;
        minimum(root->left,prev,ans);
        if(prev!=INT_MIN)
        ans = min(ans,abs(prev-root->val));
        prev = root->val;
        minimum(root->right,prev,ans);

    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        minimum(root,prev,ans);
        return ans;
    }
};
