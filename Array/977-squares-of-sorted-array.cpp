/*
link -> https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start=0,end=n-1;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(abs(nums[start])>abs(nums[end]))
            {
                ans[i]=nums[start]*nums[start];
                start++;
            }
            else{
                ans[i]=nums[end]*nums[end];
                end--;
            }
        }
        return ans;
    }
};
