//NORMAL RECURSION
#include <bits/stdc++.h> 
int ans(vector<int>& nums , int index)
{
    if(index==0) return max(0,nums[index]);
    if(index<0) return 0; 

    int pick = nums[index] + ans(nums,index-2);
    int notpick = ans(nums,index-1);

    return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    return ans(nums,nums.size()-1);
}
//NORMAL RECURSION

//MEMOIZAITON
#include <bits/stdc++.h> 
int ans(vector<int>& nums , int index, vector<int> & dp)
{
    if(index==0) return max(0,nums[index]);
    if(index<0) return 0; 

    if(dp[index]!=-1) return dp[index];
    int pick = nums[index] + ans(nums,index-2,dp);
    int notpick = ans(nums,index-1,dp);

    return dp[index] = max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size(),-1);
    return ans(nums,nums.size()-1,dp);
}
//MEMOIZAITON

//TABULATION
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];

    for(int i=1 ; i<n ; i++)
    {
        int take = nums[i] ;
        if(i>1) take+=dp[i-2];
        int nontake = dp[i-1];
        dp[i] = max(take,nontake);
    }
    return dp[n-1]; 
}
//TABULATION

//SPACE OPTIMUM
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n,-1);
    int prev = nums[0];
    int prev2 = nums[0];

    for(int i=1 ; i<n ; i++)
    {
        int take = nums[i];
        if(i>1) take += prev2;
        int nottake = prev;
        int cur = max(take,nottake);
        prev2 = prev;
        prev = cur;
    }
    return prev; 
}
//SPACE OPTIMUM

