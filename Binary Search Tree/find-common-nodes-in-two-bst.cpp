/*
link -> https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/description

Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

Example 1:

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10

Example 2:

Input:
BST1:
     10
    /  \
   2   11
  /  \
 1   3
BST2:
       2
     /  \
    1    3
Output: 1 2 3
Your Task:
You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

Constraints:
1 <= Number of Nodes <= 105
1 <= Node data <= 109


*/



class Solution
{
public:
  //Function to find the nodes that are common in both BST. 
  vector < int >findCommon (Node * root1, Node * root2)
  {
	//Your code here
	vector < int >ans;
	  stack < Node * >s1, s2;
	while (root1)
	  {
		s1.push (root1);
		root1 = root1->left;
	  }
	while (root2)
	  {
		s2.push (root2);
		root2 = root2->left;
	  }
	while (!s1.empty () && !s2.empty ())
	  {
		if (s1.top ()->data == s2.top ()->data)
		  {
			ans.push_back (s1.top ()->data);
			root1 = s1.top ()->right;
			s1.pop ();
			root2 = s2.top ()->right;
			s2.pop ();

		  }
		else if (s1.top ()->data > s2.top ()->data)
		  {
			root2 = s2.top ()->right;
			s2.pop ();
		  }
		else
		  {
			root1 = s1.top ()->right;
			s1.pop ();
		  }
		while (root1)
		  {
			s1.push (root1);
			root1 = root1->left;
		  }
		while (root2)
		  {
			s2.push (root2);
			root2 = root2->left;
		  }
	  }
	return ans;
  }
};
