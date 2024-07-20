/*
link -> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>level;
        if(!root) return ans;
        stack<TreeNode*>l;
        stack<TreeNode*>r;
        
        l.push(root);
        while(!l.empty() || !r.empty())
        {
            if(!l.empty())
            {
            
            while(!l.empty())
            {
                TreeNode* temp = l.top();
                l.pop();
                level.push_back(temp->val);
                if(temp->left)
                r.push(temp->left);
                if(temp->right)
                r.push(temp->right);
            }
            }
            
            else if(!r.empty())
            {
            
            while(!r.empty())
            {
                TreeNode* temp = r.top();
                r.pop();
                level.push_back(temp->val);
                if(temp->right)
                l.push(temp->right);
                if(temp->left)
                l.push(temp->left);
            }
            
            }
            ans.push_back(level);
            level.erase(level.begin(),level.end());
        }
        return ans;
    }
};
