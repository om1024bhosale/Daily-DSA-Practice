/*
link-> https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1?page=1&category=Strings&difficulty=Medium&sortBy=submissions
Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.

Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)

Constraints:
1 ≤ N ≤ 1000
*/
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>ans(1,1);
        while(N>1)
        {
            int carry=0,res,size=ans.size();
            for(int i=0;i<size;i++)
            {
                res=ans[i]*N+carry;
                carry=res/10;
                ans[i]=res%10;
            }
            while(carry)
            {
                ans.push_back(carry%10);
                carry/=10;
                
            }
            N--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
