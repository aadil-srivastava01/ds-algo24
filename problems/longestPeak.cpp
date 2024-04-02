/* Problem Statement:

Write a function that takes in an array of integers and returns the length of the longest peak in the array.
A peak is defined as adjacent integers in the array that are strictly increasing until they reach a tip (the highest value in the peak), at which point they become strictly decreasing. At least three Integers are required to form a peak.
For example, the Integers 1, 4, 10, 2 form a peak, but the Integers 4, 0, 10 don't and neither do the Integers 1, 2, 2, 0. Similarly, the integers 1, 2, 3 don't form a peak because there aren't any strictly decreasing integers after the 3
Sample Input
array = [1, 2, 3, 3, 4, 0, 10, 6, 5, 1, 3, 2, 3]
Sample Output
6 // 0, 10, 6, 5, -1, -3

Solution Complexity:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int longestPeak(vector<int> array)
{
    if (array.size() == 0 || array.size() == 1 || array.size() == 2)
        return 0;
    else
    {
        bool isIncresing{false};
        int currPeakLen{0};
        int maxPeakLen{0};
        int prev = array.at(1);
        bool peakFound{false};

        isIncresing = array.at(1) > array.at(0) ? true : false;
        currPeakLen = isIncresing ? 2 : 1;

        for (size_t i = 2; i < array.size(); i++)
        {
            if (array.at(i) > prev && !peakFound)
            {
                isIncresing = true;
                currPeakLen++;
                prev = array.at(i);
                continue;
            }
            if (array.at(i) < prev && (isIncresing || peakFound))
            {
                peakFound = true;
                isIncresing = false;
                currPeakLen++;
                prev = array.at(i);
                continue;
            }
            if (array.at(i) > prev && peakFound)
            {
                if (currPeakLen > maxPeakLen)
                    maxPeakLen = currPeakLen;

                currPeakLen = 2;
                peakFound = false;
                isIncresing = true;
                prev = array.at(i);
                continue;
            }
            if (peakFound)
            {
                if (currPeakLen > maxPeakLen)
                    maxPeakLen = currPeakLen;
            }
            currPeakLen = 1;
            peakFound = false;
            isIncresing = false;
            prev = array.at(i);
            continue;
        }
        if (currPeakLen > maxPeakLen && peakFound && currPeakLen >= 3)
            maxPeakLen = currPeakLen;

        return maxPeakLen;
    }
}

int main()
{
    vector<int> input = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    cout << longestPeak(input);
    return 0;
}