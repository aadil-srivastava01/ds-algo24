/* Problem Statement:

Given an array of integers between 1 and n, inclusive, where n is the length of the array, write a function that returns the first Integer that appears more than once (when the array is read from left to right).
In other words, out of all the integers that might occur more than once in the input array, your function should return the one whose first duplicate value has the minimum Index.
If no integer appears more than once, your function should return -1
Note that you're allowed to mutate the input array.
Sample Input #1
array [2, 1, 5, 2, 3, 3, 4]
Sample Output #1
2 // 2 is the first integer that appears more than once.
// 3 also appears more than once, but the second 3 appears after the second 2.  `

Solution Complexity:

Time: O(n) | Space: O(n)
Optimum: Time O(n) | Space O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int subOptimfirstDuplicateValue(vector<int> array)
{

    unordered_set<int> dupChecker;

    for (size_t idx = 0; idx < array.size(); idx++)
    {
        if (dupChecker.find(array.at(idx)) != dupChecker.end())
            return array.at(idx);
        else
            dupChecker.emplace(array.at(idx));
    }
    return -1;
}

int firstDuplicateValue(vector<int> array)
{

    int idx{0};
    for (const int val : array)
    {
        idx = val < 0 ? ((val * -1) - 1) : (val - 1);
        if (array.at(idx) < 0)
            return idx + 1;
        else
            array.at(idx) *= -1;
    }
    return -1;
}

int main()
{
    vector<int> input = {2, 1, 5, 2, 3, 3, 4};
    cout << subOptimfirstDuplicateValue(input) << endl;
    cout << firstDuplicateValue(input) << endl;
    return 0;
}