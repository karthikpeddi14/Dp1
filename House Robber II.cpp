//MY SOLUTION
#include <bits/stdc++.h> 
long long int recursion(vector<int> & value , int index, int flag)
{
    if(index==0)
    {
        if(flag==0) return value[0];
        return 0;
    }
    if(index<0) return 0;

    if(index==value.size()-1) flag = 1;
    long long pick = recursion(value, index-2, flag) + value[index];
    
    if(index==value.size()-1) flag = 0;
    long long notpick = recursion(value,index-1,flag) + 0;

    return max(pick,notpick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    return recursion(valueInHouse, valueInHouse.size()-1, 0);
}
//MY SOLUTION

//STRIVER'S
#include <bits/stdc++.h> 
long long int maximumNonAdjacentSum(vector<int> &nums, int start, int end)
{
    int n = end;
    long long prev = nums[start];
    long long prev2 = nums[start];

    for(int i=1+start ; i<n ; i++)
    {
        long long take = nums[i];
        if(i>1+start) take += prev2;
        long long nottake = prev;
        long long cur = max(take,nottake);
        prev2 = prev;
        prev = cur;
    }
    return prev; 
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    if(n==0) return 0;
    long long a = maximumNonAdjacentSum(valueInHouse,0,n-1);
    long long b = maximumNonAdjacentSum(valueInHouse,1,n);

    return max(a,b);
}
//STRIVER'S
