/*
link-> https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:
You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets
*/

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int>lps(s.size(),0);
	    int pre=0,suf=1;
	    while(suf<s.size())
	    {
	        if(s[pre]==s[suf])
	        {
	            lps[suf]=pre+1;
	            suf++;
	            pre++;
	            
	        }
	        else
	        {
	            if(pre==0)
	            {
	                lps[suf]=0;
	                suf++;
	            }
	            else{
	                pre=lps[pre-1];
	            }
	        }
	    }
	    return lps[s.size()-1];
	}
};
