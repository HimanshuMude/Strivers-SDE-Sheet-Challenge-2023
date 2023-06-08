#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int ans = 1;
    int lastOne = INT_MIN, currCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (lastOne == arr[i] - 1)
        {
            currCnt++;
            lastOne = arr[i];
        }
        else if (lastOne != arr[i])
        {
            currCnt = 1;
            lastOne = arr[i];
        }
        ans = max(ans, currCnt);
    }
    return ans;
}


