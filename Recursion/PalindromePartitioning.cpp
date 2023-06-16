#include <bits/stdc++.h>

bool checkPal(string s, int left, int right)
{
    while (left <= right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void rec(vector<vector<string>> &ans, string &s, vector<string> temp, int idx)
{
    if (idx == s.length())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        if (checkPal(s, idx, i))
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            rec(ans, s, temp, i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> ans;
    rec(ans, s, {}, 0);
    return ans;
}