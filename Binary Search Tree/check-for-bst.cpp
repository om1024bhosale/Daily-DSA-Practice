/*
link -> https://www.geeksforgeeks.org/problems/check-for-bst/1?page=1&difficulty

Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input:
   2
 /    \
1      3
        \
         5
Output: true 
Explanation: 
The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
Input:
  2
   \
    7
     \
      6
       \
        9
Output: false 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 
Input:
   10
 /    \
5      20
      /   \
     9     25
Output: false
Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
Expected Time Complexity: O(n) where n is the number of nodes in the given tree
Expected Auxiliary Space: O(Height of the given tree).

Constraints:

1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

Seen this question in a real interview before ?
Yes
No
Company Tags
VMWareFlipkartAccoliteAmazonMicrosoftOYO RoomsSamsungSnapdealFactSetHikeMakeMyTripOla CabsWalmartGoldman SachsMAQ SoftwareAdobeLinkedinQualcommBoomerang CommerceGreyOrangeWooker
*/
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void order(Node* root, vector<int>& ans)
    {
        if(!root) return;
        order(root->left,ans);
        ans.push_back(root->data);
        order(root->right,ans);
    }
    bool isBST(Node* root) {
        // Your code here
        vector<int>ans;
        order(root,ans);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]<=ans[i-1])
            return 0;
        }
        return 1;
    }
};

