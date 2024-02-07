/*
link -> https://leetcode.com/problems/permutations/description/
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

class Solution {
public:

    void permut(vector<int>& nums,vector<int> &temp, vector<vector<int> > &ans,vector<bool> &visited)
    {
        if(visited.size()==temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                temp.push_back(nums[i]);
                permut(nums,temp,ans,visited);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        vector<bool>visited(nums.size(),0);
        permut(nums,temp,ans,visited);
        return ans;
    }
};
// second approach: optimal
void permut(vector<int>& nums,int index,int n,vector<vector<int>>& ans)
    {
        if(index==n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++)
        {
            swap(nums[i],nums[index]);
            permut(nums,index+1,n,ans);
            swap(nums[i],nums[index]);
        }
    
    }
    vector<vector<int>> permute(vector<int>& nums) {
      
        vector<vector<int> >ans;
        int n=nums.size();
        permut(nums,0,n,ans);
        return ans;
    }
};
