#include <bits/stdc++.h>

void rec(vector<int> &arr, int idx, int n, vector<vector<int>> &ans, vector<int> temp)
{
    ans.push_back(temp);

    for (int i = idx; i < n; i++)
    {
        if (i != idx and arr[i - 1] == arr[i])
            continue;
        temp.push_back(arr[i]);
        rec(arr, i + 1, n, ans, temp);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    rec(arr, 0, arr.size(), ans, {});
    return ans;
}