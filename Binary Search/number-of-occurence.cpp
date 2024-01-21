/*
link ->https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Problem statement
You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.



Find the total number of occurrences of 'x' in the array/list.



Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7 3
1 1 1 2 2 3 3


Sample Output 1:
2


Explanation For Sample Input 1:
In the given list, there are 2 occurrences of integer 3.


Sample Input 2:
 5 6
 1 2 4 4 5


Sample Output 2:
 0


Explanation For Sample Input 2:
In the given list, there are 0 occurrences of integer 6.


Expected time complexity:
The expected time complexity is O(log 'n').


Constraints:
1 <= n <= 10^4
1 <= arr[i] <= 10^9
1 <= x <= 10^9
Where arr[i] represents the element i-th element in the array/list.

Time Limit: 1sec

*/

int count(vector<int>& nums, int n, int target) {
	// Write Your Code Here
	int start=0,end=n-1,mid,first=-1,last=-1;
	 while(start<=end)
       {
           mid=start+(end-start)/2;
           if(nums[mid]==target)
           {
               first=mid;
               end=mid-1;
           }
           else if(nums[mid]>target)
           {
               end=mid-1;
           }
           else{
               start=mid+1;
           }
        }
        start=0,end=nums.size()-1;
        while(start<=end)
       {
           mid=start+(end-start)/2;
           if(nums[mid]==target)
           {
               last=mid;
               start=mid+1;
           }
           else if(nums[mid]>target)
           {
               end=mid-1;
           }
           else{
               start=mid+1;
           }
        }
		if(last==-1&&first==-1) return 0;
		return last-first+1;
}
