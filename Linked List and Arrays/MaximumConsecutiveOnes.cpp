int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int j = 0, i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            k--;
        if (k < 0 and arr[j++] == 0)
            k++;
    }
    return i - j;
}
