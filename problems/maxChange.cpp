/* Problem Statement:

Non-Constructible Change
Given an array of positive integers representing the values of coins in your possession, write a function that returns the minimum amount of change (the minimum sum of money) that you cannot create. The given coins can have any positive integer value and aren't necessarily unique (I.e., you can have multiple coins of the same value).
For example, if you're given coins = [1, 2, 5], the minimum amount of change that you can't create is 4. If you're given no coins, the minimum amount of change that you can't create is 1
Sample Input
coins = [5, 7, 1, 1, 2, 3, 22]
Sample Output
20

Solution Complexity:

O(nlogn): Time | O(1): Space

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nonConstructibleChange(vector<int> &coins)
{
    if (coins.empty())
        return 1;
    sort(coins.begin(), coins.end());
    int maxFormableChange = 1;
    for (const int &coin : coins)
    {
        if (coin <= maxFormableChange)
        {
            maxFormableChange += coin;
        }
        else
        {
            break;
        }
    }
    return maxFormableChange;
}

int main()
{
    vector<int> coins{5, 7, 1, 1, 2, 3, 22};
    cout << nonConstructibleChange(coins) << endl;
    return 0;
}