/*
link -> https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/
//Recursively ie DFS
class Solution {
public:
    bool check(TreeNode* l, TreeNode* r)
    {
        if(!l && !r) return 1;
        if((!l && r)|| (l &&!r)) return 0;
        if(l->val != r->val) return 0;
        return(check(l->left,r->right)&&check(l->right,r->left));
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if((!left && right)|| (left &&!right)) return 0;
        bool ans =  check(left,right);
        return ans;
    }
};

// iterative i.e. BFS

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        queue<TreeNode* >q;
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* l = q.front();
            q.pop();
            TreeNode* r = q.front();
            q.pop();
            if(!l&&!r) continue;
            if(!l || !r || l->val!=r->val) return 0;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
            
        }
        return 1;
    }
};
