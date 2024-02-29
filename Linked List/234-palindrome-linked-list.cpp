/*
link -> https://leetcode.com/problems/palindrome-linked-list/description/

Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        {
            return true;
        }
        int count = 0;
        ListNode *temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode *curr=head, *prev=NULL;
        while(count--)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        //reversing second list.
        ListNode *front;
        prev=NULL;
        while(curr)
        {
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        ListNode *head1=head, *head2=prev;
        while(head1)
        {
            if(head1->val!=head2->val)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};
