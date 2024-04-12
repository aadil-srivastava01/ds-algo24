/* Problem Statement:

You're given an unordered list of unique integers nums in the range [1, n], where n represents the length of nums + 2 This means that two numbers in this range are missing from the list.
Write a function that takes in this list and returns a new list with the two missing numbers, sorted numerically.
Sample Input
nums [1, 4, 3]
Sample Output
[2, 5] // n is 5, meaning the completed list should be [1, 2, 3, 4, 5]

Solution Complexity:
Sub-optimal: Time: O(n) | Space: O(n)
Optimal: Time: O(n) | Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subOpmissingNumbers(vector<int> nums)
{
    vector<int> result;
    vector<int> tracker(nums.size() + 2);
    for (const auto &elem : nums)
    {
        tracker.at(elem - 1) = 1;
    }
    int idx{0};
    for (const auto &elem : tracker)
    {
        if (elem == 0)
            result.emplace_back(idx + 1);
        idx++;
    }
    sort(result.begin(), result.end());
    return result;
}

vector<int> missingNumbers(vector<int> nums)
{
    vector<int> outliers;
    for (auto num : nums)
    {
        if (num < 0)
            num *= -1;
        if (num > nums.size())
        {
            outliers.emplace_back(num);
            continue;
        }
        else
        {
            nums.at(num - 1) *= -1;
        }
    }

    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) > 0)
        {
            result.emplace_back(i + 1);
        }
    }

    if (result.size() == 0)
    {
        result.emplace_back(nums.size() + 1);
        result.emplace_back(nums.size() + 2);
    }
    else if (result.size() == 2)
    {
        sort(result.begin(), result.end());
    }
    else if (result.size() == 1)
    {
        if (outliers.at(0) == nums.size() + 2)
            result.emplace_back(outliers.at(0) - 1);
        else
            result.emplace_back(outliers.at(0) + 1);
        sort(result.begin(), result.end());
    }
    return result;
}

int main()
{
    vector<int> input = {4, 5, 1, 3};
    subOpmissingNumbers(input);
    missingNumbers(input);
    return 0;
}