// normal recursive solution 
int ans(int k ,vector<int>& height, int index)
{
    if(index == 0) return 0;
    int mini = INT_MAX;
    for(int i=1 ; i<=k ; i++)
    {
        if(index-i>=0) 
        {
            int jump = ans(k,height,index-i) + abs(height[index]-height[index-i]);
            mini = min(mini,jump);
        }
        else break;
    }
    return mini;

}
int minimizeCost(int n, int k, vector<int> &height)
{
    return ans(k,height,n-1);
}
// normal recursive solution 




// MEMOIZATION 
int ans(int k ,vector<int>& height, int index, vector<int>& dp)
{
    if(index == 0) return 0;
    if(dp[index]!=-1) return dp[index];
    int mini = INT_MAX;
    for(int i=1 ; i<=k ; i++)
    {
        if(index-i>=0) 
        {
            int jump = ans(k,height,index-i,dp) + abs(height[index]-height[index-i]);
            mini = min(mini,jump);
        }
        else break;
    }
    dp[index] = mini;
    return mini;

}
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n,-1);
    return ans(k,height,n-1,dp);
}
// MEMOIZATION




//TABULATION
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i=1 ; i<n ; i++)
    {
        int mini = INT_MAX;
        for(int j=1; j<=k ; j++)
        {
            if(i-j>=0)
            {
                int jump = dp[i-j] + abs(height[i]-height[i-j]);
                mini = min(mini,jump);
            }
        }
        dp[i] = mini;
    }
    return dp[n-1];
}
//TABULATION
