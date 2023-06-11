#include <algorithm>
int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    return unique(arr.begin(), arr.end()) - arr.begin();
}