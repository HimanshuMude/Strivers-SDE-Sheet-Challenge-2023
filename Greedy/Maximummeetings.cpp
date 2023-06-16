#include <bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<pair<int, int>, int>> vp;
    for (int i = 0; i < start.size(); i++)
    {
        vp.push_back({{end[i], i + 1}, start[i]});
    }
    sort(vp.begin(), vp.end());
    int End = -1;

    vector<int> ans;
    for (int i = 0; i < start.size(); i++)
    {
        if (vp[i].second > End)
        {
            ans.push_back(vp[i].first.second);
            End = vp[i].first.first;
        }
    }

    return ans;
}