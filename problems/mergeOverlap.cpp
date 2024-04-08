/* Problem Statement:

Write a function that takes in a non-empty array of arbitrary intervals, merges any overlapping intervals, and returns the new intervals in no particular order.
Each interval interval is an array of two integers, with interval [0] as the start of the interval and interval [1] as the end of the interval.
Note that back-to-back intervals aren't considered to be overlapping. For example, [1, 5] and [6, 7] aren't overlapping; however, [1, 6] and [6, 7] are indeed overlapping.
Also note that the start of any particular Interval will always be less than or equal to the end of that interval.
Sample Input
intervals = [[1, 2], [3, 5], [4, 7], [6, 8], [9, 10]]
Sample Output
[[1, 2], [3, 8], [9, 10]]
// Merge the intervals [3, 5], [4, 7], and [6, 8].
// The intervals could be ordered differently.

Solution Complexity:
Time: O(l(logn)) | Space : O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals)
{
    if (intervals.size() <= 1)
        return intervals;

    vector<vector<int>> result;
    vector<int> temp;
    bool hasOverlap{false};
    int p1{0};
    int p2{1};

    std::sort(intervals.begin(), intervals.end());
    while (p2 < intervals.size())
    {
        if (!hasOverlap && intervals.at(p2).at(0) <= intervals.at(p1).at(1))
        {
            if (intervals.at(p1).at(1) <= intervals.at(p2).at(1))
            {
                temp.emplace_back(intervals.at(p1).at(0));
                temp.emplace_back(intervals.at(p2).at(1));
                hasOverlap = true;
            }
            else
            {
                temp.emplace_back(intervals.at(p1).at(0));
                temp.emplace_back(intervals.at(p1).at(1));
                hasOverlap = true;
            }
        }
        else if (hasOverlap)
        {
            if (intervals.at(p2).at(0) <= temp.at(1))
            {
                if (temp.at(1) <= intervals.at(p2).at(1))
                {
                    temp.at(1) = intervals.at(p2).at(1);
                    hasOverlap = true;
                }
            }
            else
            {
                result.emplace_back(temp);
                temp.clear();
                hasOverlap = false;
                p1 = p2;
            }
        }
        else
        {
            result.emplace_back(intervals.at(p1));
            p1 = p2;
        }
        ++p2;
    }
    if (temp.size() != 0)
        result.emplace_back(temp);
    else
        result.emplace_back(intervals.at(p2 - 1));
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}};
    mergeOverlappingIntervals(intervals);
    return 0;
}