#include <algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    vector<pair<int, int>> vp;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        vp.push_back({finish[i], start[i]});
    }

    sort(vp.begin(), vp.end());
    int prev = vp[0].first;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (prev <= vp[i].second)
        {
            prev = vp[i].first;
            res++;
        }
    }
    return res;
}