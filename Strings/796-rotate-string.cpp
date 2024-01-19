/*
link -> https://leetcode.com/problems/rotate-string/description/

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
      for(int i=0;i<goal.size();i++)
      {
          int temp=goal[0];
          for(int j=0;j<goal.size()-1;j++)
          {
              goal[j]=goal[j+1];
          }
          goal[goal.size()-1]=temp;
          if(s==goal) return true;
      }
      return false;
    }
};
