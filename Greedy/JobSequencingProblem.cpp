#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] > b[1]; });

    int maxi = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxi = max(maxi, jobs[i][0]);
    }
    vector<int> temp(maxi + 1, -1);
    int maxProfit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (temp[j] == -1)
            {
                temp[j] = jobs[i][0];
                maxProfit += jobs[i][1];
                break;
            }
        }
    }

    return maxProfit;
}
