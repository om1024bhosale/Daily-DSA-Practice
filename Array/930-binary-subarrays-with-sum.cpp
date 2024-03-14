/*
link -> https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

class Solution {
public:
    int sumAtMost(const vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int res = 0;
        int prev = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            while (cur > goal)
                cur -= nums[prev++];
            res += i - prev + 1;
        }

        return res;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumAtMost(nums, goal) - sumAtMost(nums, goal - 1);
    }
};
