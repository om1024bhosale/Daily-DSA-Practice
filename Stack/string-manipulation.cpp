/*
link -> https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

Tom is a string freak. He has got sequences of  n words to manipulate. If in a sequence, two same words come together then hell destroy each other. He wants to know the number of words left in the sequence after this pairwise destruction.
 

Example 1:

Input:
5
v[] = {"ab", "aa", "aa", "bcd", "ab"}
Output:
3
Explanation:
ab aa aa bcd ab
After the first iteration, we'll have: ab bcd ab
We can't further destroy more strings and
hence we stop and the result is 3. 
 

Example 2:

Input:
4
v[] = {"tom", "jerry", "jerry", "tom"}
Output:
0
Explanation:
tom jerry jerry tom
After the first iteration, we'll have: tom tom
After the second iteration: 'empty-array' 
Hence, the result is 0. 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function removeConsecutiveSame() which takes the array A[] and its size N as inputs and returns the number of words left per sequence.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 100
1 ≤ |Si| ≤ 50
*/

class Solution{
    public:
    int removeConsecutiveSame(vector <string > v) 
    {
        // Your code goes here
        stack<string>s;
        for(int i=0;i<v.size();i++)
        {
            if(s.empty()) s.push(v[i]);
            else{
            
            if(v[i]==s.top())
            {
                s.pop();
            }
            else{
                s.push(v[i]);
            }
            }
        }
        return s.size();
    } 
};
