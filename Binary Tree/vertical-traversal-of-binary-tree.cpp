/*
link -> https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*104



*/

class Solution
{
    public:
    
    void extreme(Node* root, int &l, int &r, int pos)
    {
        if(!root) return;
        
        l = min(pos,l);
        r = max(pos,r);
        
        extreme(root->left,l,r,pos-1);
        extreme(root->right,l,r,pos+1);
        
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        int l=0,r=0;
        extreme(root,l,r,0);
        vector<vector<int>>positive(r+1);
        vector<vector<int>>negative(abs(l)+1);
        vector<int>ans;
        queue<Node* >q;
        queue<int>index;
        q.push(root);
        index.push(0);
        while(!q.empty())
        {
           Node* temp = q.front();
           q.pop();
           int pos = index.front();
           index.pop();
           if(pos<0)
           {
               negative[abs(pos)].push_back(temp->data);
           }
           else
           {
               positive[pos].push_back(temp->data);
           }
           if(temp->left)
           {
               q.push(temp->left);
               index.push(pos-1);
           }
           if(temp->right)
           {
               q.push(temp->right);
               index.push(pos+1);
           }
        }
        for(int i=negative.size()-1;i>0;i--)
        for(int j=0;j<negative[i].size();j++)
        ans.push_back(negative[i][j]);
            
        for(int i =0;i<positive.size();i++)
        for(int j=0;j<positive[i].size();j++)
        ans.push_back(positive[i][j]);
            
        return ans;
        
    }
};
