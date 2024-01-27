/*
Concept used is MERGE SORT.
link->https://leetcode.com/problems/sort-an-array/
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/
class Solution {
public:

    void merge(vector<int>&arr,int start,int mid,int end)
    {
        vector<int>temp(end-start+1);
        int left=start,right=mid+1,index=0;
        while(left<=mid && right<=end)
        {
            if(arr[left]<=arr[right])
            {
                temp[index]=arr[left];
                index++;
                left++;
            }
            else
            {
                temp[index]=arr[right];
                index++;
                right++;
            }
        }
        //if some element is left then we will add those elements.
        while(left<=mid)
        {
            temp[index]=arr[left];
            index++;
            left++;
        }
        while(right<=end)
        {
            temp[index]=arr[right];
            index++;
            right++;
        }
        //now we have to add these element in our original array.

        index=0;
        while (start<=end)
        {
            arr[start]=temp[index];
            start++;
            index++;
        }
    }

    void mergesort(vector<int>&arr,int start,int end){
        if(start==end) return;
        int mid = start+(end-start)/2;
        //for left array
        mergesort(arr,start,mid);
        //for right array
        mergesort(arr,mid+1,end);
        //now merging and sorting
        merge(arr,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
