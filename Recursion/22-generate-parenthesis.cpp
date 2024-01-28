/*
link -> https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:

    void parenthesis(string &temp,vector<string> &ans, int left, int right, int n)
    {
        if(left+right== 2*n)
        {
            ans.push_back(temp);
            return;
        }
        //left
        if(left<n)
        {
            temp.push_back('(');
            parenthesis(temp,ans,left+1,right,n);
            temp.pop_back();
        }
        if(right<left)
        {
            temp.push_back(')');
            parenthesis(temp,ans,left,right+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parenthesis(temp,ans,0,0,n);
        return ans;
    }
};
