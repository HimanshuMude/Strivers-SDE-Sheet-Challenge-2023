#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{

    int n = arr.size();
    // Write your code here
    unordered_map<int, int> mp;
    int sum = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            len = max(len, i + 1);
        }
        if (mp.find(sum) != mp.end())
        {
            len = max(len, i - mp[sum]);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return len;
}