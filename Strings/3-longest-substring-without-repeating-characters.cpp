/*
link-> https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1138397637/
Given a string s, find the length of the longest 
substring
 without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <bool>count(256,0);
        int first=0,last=0,len=0;
        while(last<s.size())
        {
            //checking for repeating characters.
            while(count[s[last]])
            {
                count[s[first]]=0;
                first++;
            }
            count[s[last]]=1;
            len=max(len,last-first+1);
            last++;
        }
        return len;
    }
};
