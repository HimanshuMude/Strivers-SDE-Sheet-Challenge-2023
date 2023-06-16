#include <bits/stdc++.h>
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    vector<pair<double, int>> vp;
    for (auto &i : items)
    {
        vp.push_back({(1.0 * i.second) / i.first, i.first});
    }

    sort(vp.rbegin(), vp.rend());

    double maxVal = 0;

    for (int i = 0; i < n; i++)
    {
        int weight = vp[i].second;
        double frac = vp[i].first;
        if (w > weight)
        {
            w -= weight;
            maxVal += (frac * weight);
        }
        else
        {
            maxVal += (frac * w);
            break;
        }
    }

    return maxVal;
}