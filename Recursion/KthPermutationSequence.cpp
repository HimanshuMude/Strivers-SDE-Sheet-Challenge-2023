#include <algorithm>

string kthPermutation(int n, int k)
{
    // Write your code here.
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k--;
    string ans = "";
    while (1)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
        {
            break;
        }
        k %= fact;
        fact /= nums.size();
    }
    return ans;
}
