/*
link -> https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457
Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 1021
*/

class Solution
{
    public:
    Node* reversell(Node *&head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* front = NULL;
        while(curr)
        {
            front = curr->next;
            curr->next = prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp = reversell(head);
        Node* tail = temp;
        int sum = 0,carry=0;
        sum = tail->data+1;
        carry = sum/10;
        tail->data = sum%10;
        tail = tail->next;
        while(carry && tail)
        {
             sum = tail->data+carry;
            tail->data = (sum)%10;
            carry=sum/10;
            tail = tail->next;
        }
        tail = temp;
        if(carry)
        {
            while(tail->next)
            {
                tail=tail->next;
            }
            Node* extra = new Node(1);
            tail->next = extra;
        }
        head = reversell(temp);
        return head;
    }
};
