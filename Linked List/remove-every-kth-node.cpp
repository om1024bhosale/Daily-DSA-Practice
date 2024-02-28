/*
link -> https://www.geeksforgeeks.org/problems/remove-every-kth-node/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given a singly linked list, your task is to remove every kth node from the linked list. 

Example 1:

Input:
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
k = 2
Output: 1 -> 3 -> 5 -> 7
Explanation: After removing each 2nd node of the linked list  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8  .
The resultant linked list will be: 1 -> 3 -> 5 -> 7
Example 2:

Input:
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 
k = 3
Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: After removing each 3rd node of the linked list  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10.
The resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Your Task:
The task is to complete the function deleteK() which takes head of linked list and integer k as input parameters and delete every kth nodes from the linked list and return its head.

Constraints:
1 <= n <= 105
1 <= element of linked list <= 106
1 <= k <= n
*/

Node* deleteK(Node *head,int k)
{
  //Your code here
  if(k==1)
  {
      return NULL;
  }
  int count=1;
  Node *curr=head,*prev=NULL;
  while(curr)
  {
      if(count==k)
      {
          prev->next=curr->next;
          delete curr;
          curr=prev->next;
          count=1;
      }
      else{
            prev=curr;
          curr=curr->next;
          count++;    
       }
      
   }
  return head;
}
