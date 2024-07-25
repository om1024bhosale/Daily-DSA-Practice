/*
link -> https://www.geeksforgeeks.org/problems/merge-two-bst-s/description

Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O(m+n)
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes ≤ 105
*/

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root, vector<int>& arr)
    {
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>v1;
        vector<int>v2;
        vector<int>ans;
        inorder(root1,v1);
        inorder(root2, v2);
        int i=0,j=0;
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]<v2[j]) ans.push_back(v1[i++]);
            else ans.push_back(v2[j++]);
        }
        while(i<v1.size())
        {
            ans.push_back(v1[i++]);
        }
        while(j<v2.size())
        {
            ans.push_back(v2[j++]);
        }
        return ans;
    }
};
