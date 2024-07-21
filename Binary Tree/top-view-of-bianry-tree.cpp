/*
link -> https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105
 


*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void extreme(Node* root, int&l, int&r, int pos)
    {
        if(!root) return;
        l = min(pos,l);
        r = max(pos,r);
        extreme(root->left,l,r,pos-1);
        extreme(root->right,l,r,pos+1);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        int l=0,r=0;
        extreme(root,l,r,0);
        vector<int>ans(r-l+1);
        vector<int>visited(r-l+1);
        queue<Node* >q;
        queue<int>index;
        q.push(root);
        index.push(-1*l);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            if(!visited[pos])
            {
                visited[pos]=1;
                ans[pos]=temp->data;
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
        return ans;
    }

};
