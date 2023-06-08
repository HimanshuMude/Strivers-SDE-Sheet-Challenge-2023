#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    int n = input.size();
    unordered_set<char> st;
    int lo = 0, hi = 0, ans = 0;
    while (hi < n)
    {
        if (st.find(input[hi]) != st.end())
        {
            st.erase(input[lo]);
            lo++;
        }
        else
        {
            st.insert(input[hi]);
            ans = max(ans, hi - lo + 1);
            hi++;
        }
    }

    return ans;
}