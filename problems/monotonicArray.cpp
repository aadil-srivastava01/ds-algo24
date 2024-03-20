/* Problem Statement:

Write a function that takes in an array of integers and returns a boolean representing whether the array is monotonic.
An array is said to be monotonic if its elements, from left to right, are entirely non-increasing or entirely non-decreasing.
Non-increasing elements aren't necessarily exclusively decreasing; they simply don't Increase. Similarly, non-decreasing elements aren't necessarily exclusively increasing; they simply don't decrease.
Note that empty arrays and arrays of one element are monotonic.
Sample Input
array = [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]
Sample Output
true

Solution Complexity:
Time : O(n) | O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMonotonic(vector<int> &array)
{
    if (array.size() == 0 | array.size() == 1)
        return true;

    else
    {
        bool isTrendSet{false};
        bool isIncreasing{false};
        int prevElem{array.at(0)};

        for (int idx = 1; idx < array.size(); idx++)
        {
            if (isTrendSet == false && prevElem != array.at(idx))
            {
                isTrendSet = true;
                isIncreasing = prevElem < array.at(idx) ? true : false;
            }
            else if (isTrendSet && isIncreasing)
            {
                if (prevElem > array.at(idx))
                    return false;
            }
            else if (isTrendSet && !isIncreasing)
            {
                if (prevElem < array.at(idx))
                    return false;
            }
            prevElem = array.at(idx);
        }
    }
    return true;
}

int main()
{
    vector<int> array{-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    cout << isMonotonic(array) << endl;
    return 0;
}