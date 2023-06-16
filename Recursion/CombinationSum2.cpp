#include <algorithm>

void rec(vector<int> &arr, vector<vector<int>> &ans, int sum, int idx, int target, int n, vector<int> temp)
{

    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i != idx and arr[i - 1] == arr[i])
            continue;
        temp.push_back(arr[i]);
        rec(arr, ans, sum + arr[i], i + 1, target, n, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    rec(arr, ans, 0, 0, target, n, {});
    return ans;
}
