/*
link ->https://www.geeksforgeeks.org/problems/is-binary-tree-heap/description

Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000


*/

class Solution {
  public:
    int count(struct Node* tree)
    {
        if(!tree) return 0;
        return 1+count(tree->left)+count(tree->right);
    }
    bool cbt(struct Node* tree, int index, int size)
    {
        if(!tree) return 1;
        if(index>=size) return 0;
        return cbt(tree->left,2*index+1,size) && cbt(tree->right,2*index+2,size);
    }
    bool maxheap(struct Node* tree)
    {
        if(tree->left)
        {
            if(tree->data<tree->left->data) return 0;
            if(!maxheap(tree->left)) return 0;
            
        }
        if(tree->right)
        {
            if(tree->data<tree->right->data)return 0;
            return maxheap(tree->right);
        }
        return 1;
    }
    bool isHeap(struct Node* tree) {
        // code here
        int size = count(tree);
        bool check = cbt(tree,0,size);
        if(!check) return 0;
        return maxheap(tree);
        
    }
};
