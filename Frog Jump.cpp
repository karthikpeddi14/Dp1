#include <bits/stdc++.h> 
int ans(int index , vector<int> & heights, vector<int> &arr)
{
    if(index==0) return 0;
    if(arr[index]!=-1) return arr[index];

    int left = ans(index-1,heights,arr) + abs(heights[index]- heights[index-1]);
    int right = INT_MAX;
    if(index!=1) right = ans(index-2,heights,arr) + abs(heights[index] - heights[index-2]);
    return arr[index] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> arr(n,-1);
    return ans(n-1, heights, arr);
}
