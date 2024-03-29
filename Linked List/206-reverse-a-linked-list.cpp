/*
link -> https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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

/*
 First Solution:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;
        while(temp !=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int i=ans.size()-1;
        temp=head;
        while(temp)
        {
            temp->val=ans[i];
            i--;
            temp=temp->next;
        }
        return head;

    }
};
*/
/*
 Second Approach:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head,*prev=NULL,*fut=NULL;
        while(curr!=NULL)
        {
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        
        head=prev;
        return head;
    }
};
*/


//Third Approach:
class Solution {
public:

    ListNode* reverse(ListNode* curr,ListNode* prev)
    {
        if(curr==NULL) return prev;

        ListNode* fut = curr->next;
        curr->next=prev;
        return reverse(fut,curr);

    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL);
    }
};

