/*
link -> https://www.geeksforgeeks.org/problems/level-order-traversal/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

Given a root of a binary tree with n nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:
1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:
10 20 30 40 60
Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
0 ≤ Data of a node ≤ 109


*/

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*>q;
      vector<int>ans;
      Node* temp;
      q.push(root);
      while(!q.empty())
      {
          temp = q.front();
          q.pop();
          ans.push_back(temp->data);
          if(temp->left)
          q.push(temp->left);
          if(temp->right)
          q.push(temp->right);
      }
      return ans;
    }
};
