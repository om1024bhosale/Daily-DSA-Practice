/*
link -> https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

Given a binary tree. Find the postorder traversal of the tree without using recursion. Return a list containing the postorder traversal of the tree, calculated without using recursion.

Examples :

Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1
Explanation: Postorder traversal (Left->Right->Root) of the tree is 4 5 2 3 1.
Input:
             8
          /      \
        1          5
         \       /   \
          7     10    6
           \   /
            10 6

Output: 10 7 1 6 10 6 5 8 
Explanation: Postorder traversal (Left->Right->Root) of the tree is 10 7 1 6 10 6 5 8 .
 
Expected time complexity: O(n)
Expected auxiliary space: O(n)
 
Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/

class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        while(root)
        {
            //LRN --->NRL
            
            while(root)
            {
                if(!root->right)
                {
                    ans.push_back(root->data);
                    root = root->left;
                }
                else{
                    Node* curr = root->right;
                    while(curr->left && curr->left!=root)
                    curr = curr->left;
                    
                    if(!curr->left)
                    {
                        ans.push_back(root->data);
                        curr->left = root;
                        root = root->right;
                    }
                    else
                    {
                        curr->left = NULL;
                        root = root->left;
                    }
                }
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};
