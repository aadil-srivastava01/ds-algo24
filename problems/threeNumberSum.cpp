/* Problem Statement:



Solution Complexity:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> twoNumberSum(vector<int> &array, size_t beginIndex,
                                 int &currentTargetSum, const int &num,
                                 vector<vector<int>> &result)
{

    size_t beginPointer = beginIndex;
    size_t endPointer = array.size() - 1;
    while (beginPointer <= endPointer)
    {
        if ((array.at(beginPointer) + array.at(endPointer)) == currentTargetSum)
        {
            result.emplace_back(num, array.at(beginPointer), array.at(endPointer));
            beginPointer++;
            endPointer--;
            continue;
        }
        else if ((array.at(beginPointer) + array.at(endPointer)) > currentTargetSum)
            endPointer--;
        else
            beginPointer++;
    }
    result;
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
    sort(array.begin(), array.end());
    int currentTargetSum;
    size_t currentIdx{1};
    vector<vector<int>> result;
    for (const int &num : array)
    {
        currentTargetSum = targetSum - num;
        twoNumberSum(array, currentIdx, currentTargetSum, num, result);
        currentIdx++;
    }
    return result;
}

int main()
{

    return 0;
}