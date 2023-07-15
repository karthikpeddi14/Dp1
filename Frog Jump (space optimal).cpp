#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    int before_before = 0;
    int before = abs(heights[1]-heights[0]);

    for(int i=2; i<n ; i++)
    {
        int left = before + abs(heights[i]-heights[i-1]);
        int right = before_before +abs(heights[i] - heights[i-2]);
        int cur = min(left,right);
        before_before = before;
        before = cur;
    }
    return before;
}
