/*
link -> https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/
class Solution {
public:

    void subarrays(vector<int>& arr,int n,int index,vector<vector<int> >& ans,vector<int>& temp)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }
        //if not to insert in temp;
        subarrays(arr,n,index+1,ans,temp);
        //if to insert in temp
        temp.push_back(arr[index]);
        subarrays(arr,n,index+1,ans,temp);
        //since we passed refernce of temp we have to popback the element so that the result is not changed.
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        subarrays(nums,nums.size(),0,ans,temp);
        return ans;
    }
};
