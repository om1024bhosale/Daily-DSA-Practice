/*
link -> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

class Solution {
public:
    int find(vector<int>& preorder, int target,int start, int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(preorder[i]==target) return i;
        }
        return -1;
    }
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index )
    {
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        int pos = find(inorder,root->val,start,end);
        root->left = tree(preorder,inorder,start,pos-1,index);
        root->right = tree(preorder,inorder,pos+1,end,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* ans = tree(preorder,inorder,0,inorder.size()-1,index);
        return ans;
    }
};
