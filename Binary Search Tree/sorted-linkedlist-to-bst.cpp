/*
link -> https://www.geeksforgeeks.org/problems/sorted-list-to-bst/description

Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Note: There might be nodes with the same value.

Example 1:

Input:
Linked List: 1->2->3->4->5->6->7
Output:
4 2 1 3 6 5 7
Explanation :
The BST formed using elements of the 
linked list is,
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7  
Hence, preorder traversal of this 
tree is 4 2 1 3 6 5 7
Example 2:

Input:
Linked List : 1->2->3->4
Ouput:
3 2 1 4
Explanation:
The BST formed using elements of the 
linked list is,
      3   
    /  \  
   2    4 
 / 
1
Hence, the preorder traversal of this 
tree is 3 2 1 4
Your task :
You don't have to read input or print anything. Your task is to complete the function sortedListToBST(), which takes head of the linked list as an input parameter and returns the root of the BST created.
 
Expected Time Complexity: O(N), N = number of Nodes
Expected Auxiliary Space: O(N), N = number of Nodes
 
Constraints:
1 ≤ Number of Nodes ≤ 106
1 ≤ Value of each node ≤ 106

*/

class Solution{
  public:
    TNode* bst(vector<int>& tree, int s, int e)
    {
        if(s>e) return NULL;
        int m = s+(e-s+1)/2;
        TNode* root = new TNode(tree[m]);
        root->left =  bst(tree,s,m-1);
        root->right = bst(tree,m+1,e);
        return root;
    }
    TNode* sortedListToBST(LNode *head) {
        //code here
        vector<int>tree;
        while(head)
        {
            tree.push_back(head->data);
            head = head->next;
        }
        return bst(tree,0,tree.size()-1);
    }
};
