/*
link: https://practice.geeksforgeeks.org/problems/sort-a-string2943/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

Example 1:

Input:
S = "edcab"
Output: "abcde"
Explanation: characters are in ascending
order in "abcde".
Example 2:

Input:
S = "xzy"
Output: "xyz"
Explanation: characters are in ascending
order in "xyz".


Your Task:  
You don't need to read input or print anything. Your task is to complete the function sort() which takes the string as inputs and returns the modified string.

Expected Time Complexity: O(|S| * log |S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 105
S contains only lowercase alphabets.
*/

string sort(string s){
    //complete the function here
    vector<int>count(26,0);
    for(int i=0;i<s.size();i++)
    {
        count[s[i]-'a']++;
    }
    
    string ans;
    for(int i=0;i<26;i++)
    {
        char c='a'+i;
        while(count[i])
        {
            ans+=c;
            count[i]--;
        }
    }
    return ans;
}
