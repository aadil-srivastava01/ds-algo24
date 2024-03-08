/* Problem Statement:

Three Number Sum
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold.
If no three numbers sum up to the target sum, the function should return an empty array.

Sample Input
array = [12, 3, 1, 2, 6, 5, 8, 6] targetSum = 0
Sample Output
[[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]

Solution Complexity:

1st Try: O(n^2) Time | O(n) Space

*/
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;
void twoNumberSum(vector<int> &array, size_t beginIndex,
                  int &currentTargetSum, const int &num,
                  vector<vector<int>> &result)
{

    int beginPointer = beginIndex;
    int endPointer = array.size() - 1;
    vector<int> tmp(3);
    while (beginPointer < endPointer)
    {
        if ((array.at(beginPointer) + array.at(endPointer)) == currentTargetSum)
        {
            // result.emplace_back(num, array.at(beginPointer), array.at(endPointer));
            vector<int> tmp;
            tmp.push_back(num);
            tmp.push_back(array.at(beginPointer));
            tmp.push_back(array.at(endPointer));
            result.push_back(tmp);
            beginPointer++;
            endPointer--;
            continue;
        }
        else if ((array.at(beginPointer) + array.at(endPointer)) > currentTargetSum)
            endPointer--;
        else
            beginPointer++;
    }
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
    sort(array.begin(), array.end());
    int currentTargetSum;
    int currentIdx{1};
    vector<vector<int>> result;
    for (int &num : array)
    {
        currentTargetSum = targetSum - num;
        twoNumberSum(array, currentIdx, currentTargetSum, num, result);
        currentIdx++;
    }
    return result;
}

int main()
{
    vector<int> array{12, 3, 1, 2, 6, 5, 8, 6};
    int targetSum = 0;
    auto result = threeNumberSum(array, targetSum);
    for (auto &triplet : result)
    {
        cout << "[";
        {
            for (auto &element : triplet)
                cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}