#include <bits/stdc++.h>

void rec(vector<int> &nums, int sum, int idx, int n, vector<int> &ans)
{
    if (idx == n)
    {
        ans.push_back(sum);
        return;
    }

    rec(nums, sum + nums[idx], idx + 1, n, ans);
    rec(nums, sum, idx + 1, n, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    int n = num.size();
    rec(num, 0, 0, n, ans);

    sort(ans.begin(), ans.end());
    return ans;
}