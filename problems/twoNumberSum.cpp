/* Problem Statement:

Two Number Sum
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers In the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.
Note that the target sum has to be obtained by summing two different integers in the array; you can't add a single integer to itself in order to obtain the target sum.
You can assume that there will be at most one pair of numbers summing up to the target sum.
Sample Input
array = [3, 5, 8, 11, 1, -1, 6]
targetSum = 10

Sample Output:
[11, -1]

Solution Complexity:
O(n): Time & O(n): Space

*/

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    unordered_set<int> refMap;
    int diff{0};
    for (const int &num : array)
    {
        diff = targetSum - num;
        if (refMap.find(num) != refMap.end())
        {
            return vector<int>{num, diff};
        }
        else
        {
            refMap.emplace(diff);
        }
    }

    return {};
}

int main()
{
    vector<int> inputarr{3, 5 - 4, 8, 11, 1, -1, 6};
    for (const auto &val : twoNumberSum(inputarr, 10))
        cout << val << endl;
    return 0;
}