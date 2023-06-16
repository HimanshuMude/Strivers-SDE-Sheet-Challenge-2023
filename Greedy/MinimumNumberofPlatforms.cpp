int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 1, j = 0, currPlat = 1, maxPlat = 1;

    while (i < n and j < n)
    {
        if (at[i] <= dt[j])
        {
            currPlat++;
            i++;
        }
        else
        {
            currPlat--;

            j++;
        }
        maxPlat = max(maxPlat, currPlat);
    }
    return maxPlat;
}