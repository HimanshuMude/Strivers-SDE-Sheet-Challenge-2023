#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    vector<long> pre(n), suf(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = max(pre[i - 1], arr[i]);
    }
    suf[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = max(suf[i + 1], arr[i]);
    }
    long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max((min(pre[i], suf[i]) - arr[i]), (long)0);
    }
    return ans;
}