/*
link -> https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1?page=1&difficulty%5B%5D=0&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions

Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

Constraints:
1 <= N <= 105
1 <= K <= N

Seen this question in a real interview before ?
Yes
No
Company Tags
AccoliteAmazonMicrosoftSamsungSAP Labs
*/

class Solution
{
    public:
    void inorder(Node* root, int& k, int& ans)
    {
        if(!root) return;
        inorder(root->right,k,ans);
        k--;
        if(k>=0)
        ans = root->data;
        if(k<=0) return;
        inorder(root->left,k,ans);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int ans = 0;
        inorder(root,k,ans);
        return ans;
    }
};
