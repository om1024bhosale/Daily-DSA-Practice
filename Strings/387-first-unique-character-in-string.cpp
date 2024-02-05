/*
link ->https://leetcode.com/problems/first-unique-character-in-a-string/?envType=daily-question&envId=2024-02-05

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/
class Solution {
public:
   
    int firstUniqChar(string s) 
    {
       vector<int>freq(26,0);
       for(int i=0;i<s.size();i++)
       {
           freq[s[i]-'a']++;
       }
       for(int i=0; i<s.size(); i++){
            if(freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
