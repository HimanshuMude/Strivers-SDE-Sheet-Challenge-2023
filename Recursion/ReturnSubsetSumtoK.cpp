#include <algorithm>

void rec(vector<int> &arr, vector<vector<int>> &ans, int idx, int sum, int k, int n, vector<int> temp)
{
    if (idx == n)
    {
        if (sum == k)
        {
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[idx]);
    rec(arr, ans, idx + 1, sum + arr[idx], k, n, temp);
    temp.pop_back();
    rec(arr, ans, idx + 1, sum, k, n, temp);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    rec(arr, ans, 0, 0, k, n, {});
    return ans;
}