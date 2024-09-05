/*
link -> https://leetcode.com/problems/reorder-list/description/

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

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
    void reorderList(ListNode* head) {
       vector<int>arr;
       ListNode* temp = head;
       while(temp)
       {
        arr.push_back(temp->val);
        temp = temp->next;
       }
       int start = 0,end = arr.size()-1;
       temp = head;
       while(start<end)
       {
        temp->val = arr[start];
        temp = temp->next;
        temp->val = arr[end];
        start++;
        end--;
        temp = temp->next;
       }
       if(arr.size()%2) temp->val = arr[start];
       

    }
};
