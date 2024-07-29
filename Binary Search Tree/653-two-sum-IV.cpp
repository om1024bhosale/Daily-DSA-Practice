/*
link -> https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr)
    {
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        int start = 0,end=arr.size()-1;
        while(start<end)
        {
            if(arr[start]+arr[end]==k) return 1;
            if(arr[start]+arr[end]>k) end--;
            else start++;
        }
        return 0;
    }
};
