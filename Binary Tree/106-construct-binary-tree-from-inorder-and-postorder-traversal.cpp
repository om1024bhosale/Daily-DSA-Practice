/*
link -> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

class Solution {
public:
    int find(const vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1; // This should never happen if the input is valid
    }

    TreeNode* tree(const vector<int>& inorder, const vector<int>& postorder, int start, int end, int& postIndex) {
        if (start > end) return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int inorderIndex = find(inorder, root->val, start, end);

        // Note that we first construct the right subtree and then the left subtree
        root->right = tree(inorder, postorder, inorderIndex + 1, end, postIndex);
        root->left = tree(inorder, postorder, start, inorderIndex - 1, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return tree(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};
