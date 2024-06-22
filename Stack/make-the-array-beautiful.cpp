/*
link -> https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

If two adjacent integers are different i.e. one of them is negative and other is non-negative, remove them.
Return the beautiful array after performing the above operation.

Note:An empty array is also a beautiful array. There can be many adjacent integers which are different as stated above. So remove different adjacent integers as described above from left to right.

Example 1:

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.
Example 2:

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function makeBeautiful() which takes an array as an input parameter and returns an array.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)


Constraints:
1 <= size of the array <= 105
-105 <= arr[i] <= 105
*/
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            if(st.empty()) st.push(arr[i]);
            else if(arr[i]>=0)
            {
                if(st.top()>=0)
                {
                    st.push(arr[i]);
                }
                else{
                    st.pop();
                }
            }
            else{
                if(st.top()<0)
                {
                    st.push(arr[i]);
                }
                else
                {
                    st.pop();
                }
            }
        }
        vector<int>ans(st.size());
        int i = st.size()-1;
        while(!st.empty())
        {
            ans[i] = st.top();
            i--;
            st.pop();
        }
        return ans;
    }
};
