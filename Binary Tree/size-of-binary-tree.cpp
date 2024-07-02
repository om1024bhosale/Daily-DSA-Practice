/*
link -> https://www.geeksforgeeks.org/problems/size-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

Given a binary tree of size n, you have to count the number of nodes in it. For example, the count of nodes in the tree below is 4.

        1
     /      \
   10      39
  /
5

Example 1:
Input:
1 2 3
Output:
3
Explanation:
Given Tree is :
                              1
                             /  \
                            2   3
There are 3 nodes in the tree.
Example 2:
Input:
10 5 9 N 1 3 6 
Output:
6
Explanation:
Given Tree is :
                              10
                             /  \
                           5     9
                            \    / \
                             1 3   6
There are 6 nodes in the tree.
User Task:
You don't need to read input or print anything. Your task is to complete the function getSize() which takes the tree head node and returns an integer representing the number of nodes in the tree.

Expected Time Complexity: O(n)
Expected Auxillary Space: O(h), where h is the height of the binary tree

Constraints:
1 <= n <= 105
1 <= values of nodes <= 106
*/
/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* node) {
        // code here
        if(!node) return 0;
        return (1+getSize(node->left)+getSize(node->right));
    }
};
