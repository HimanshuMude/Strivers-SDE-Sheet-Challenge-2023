#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    // Write your code here
    int coins[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int k = 8;
    int totalCoins = 0;
    while (amount != 0 and k >= 0)
    {
        int curr = coins[k];
        totalCoins += (amount / curr);
        amount -= (amount / curr) * curr;
        k--;
    }
    return totalCoins;
}
