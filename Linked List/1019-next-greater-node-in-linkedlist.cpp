/*
link -> https://leetcode.com/problems/next-greater-node-in-linked-list/description/

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>temp;
        while(head)
        {
            temp.push_back(head->val);
            head = head->next;
        }
        stack<int>st;
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && temp[i]>temp[st.top()])
            {
                ans[st.top()] = temp[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
