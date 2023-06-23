#include <bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount)
{
    // Write your code here
    int coins = 0;
    while (amount > 0)
    {
        if (amount >= 1000)
        {
            amount -= 1000;
            coins++;
        }
        else if (amount >= 500)
        {
            amount -= 500;
            coins++;
        }
        else if (amount >= 100)
        {
            amount -= 100;
            coins++;
        }
        else if (amount >= 50)
        {
            amount -= 50;
            coins++;
        }
        else if (amount >= 20)
        {
            amount -= 20;
            coins++;
        }
        else if (amount >= 10)
        {
            amount -= 10;
            coins++;
        }
        else if (amount >= 5)
        {
            amount -= 5;
            coins++;
        }
        else if (amount >= 2)
        {
            amount -= 2;
            coins++;
        }
        else if (amount >= 1)
        {
            amount -= 1;
            coins++;
        }
    }
    return coins;
}
