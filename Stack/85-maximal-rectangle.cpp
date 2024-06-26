/*
link -> https://leetcode.com/problems/maximal-rectangle/description/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size(),index;
        stack<int>st;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                 index = st.top();
                st.pop();
                if(!st.empty())
                {
                    ans = max(ans,heights[index]*(i-st.top()-1));
                }
                else{
                    ans = max(ans,heights[index]*i);
                }
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int index = st.top();
            st.pop();
            if(!st.empty())
            {
                ans = max(ans,heights[index]*(n-st.top()-1));
            }
            else{
                ans = max(ans,heights[index]*n);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
         vector<int>heights(col,0);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0')
                {
                    heights[j]=0;
                }
                else{
                    heights[j]++;
                }
            }
            ans = max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};
