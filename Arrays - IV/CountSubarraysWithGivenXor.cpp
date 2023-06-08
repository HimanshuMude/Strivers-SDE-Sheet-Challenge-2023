#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int preXor = 0, cnt = 0;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        preXor ^= arr[i];
        if (preXor == x)
            cnt++;
        if (mp.find(preXor ^ x) != mp.end())
        {
            cnt += mp[preXor ^ x];
        }
        mp[preXor]++;
    }
    return cnt;
}