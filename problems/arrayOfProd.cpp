/* Problem Statement:
Write a function that takes in a non-empty array of integers and returns an array of the same length, where each element in the output array is equal to the product of every other number in the input array.
In other words, the value at output [i] is equal to the product of every number in the input array other than input[i].`
Note that you're expected to solve this problem without using division.
Sample Input
array [5, 1, 4, 2]
Sample Output
[8, 40, 10, 20]
// 8 is equal to 1 x 4 x 2
// 40 is equal to 5 x 4 x 2
// 10 is equal to 5 x 1 x 2
// 20 is equal to 5 x 1 x 4

Solution Complexity:
Time: O(n) | Space: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayOfProducts(vector<int> array)
{
    long prod{1};
    for (const auto &item : array)
    {
        prod *= item;
    }
    for (size_t idx = 0; idx < array.size(); idx++)
    {
        array.at(idx) /= (prod / array.at(idx));
    }
    return array;
}

void prodCalcRight(vector<int> &array, unordered_map<int, int> &table, int idx)
{

    if (idx == array.size() - 1)
        table[idx] = 1;
    else
    {
        table[idx] = array.at(idx + 1) * table[idx + 1];
    }
    return;
}

void prodCalcLeft(vector<int> &array, unordered_map<int, int> &table, int idx)
{

    if (idx == 0)
        table[idx] = 1;
    else
    {
        table[idx] = array.at(idx - 1) * table[idx - 1];
    }
    return;
}

vector<int> arrayOfProductsDS(vector<int> array)
{
    unordered_map<int, int> rightable;
    unordered_map<int, int> leftable;
    vector<int> result;
    for (int i = static_cast<int>(array.size()) - 1; i >= 0; i--)
    {
        prodCalcRight(array, rightable, i);
    }
    for (int i = 0; i < array.size(); i++)
    {
        prodCalcLeft(array, leftable, i);
        result.emplace_back(leftable[i] * rightable[i]);
    }
    return result;
}

int main()
{
    vector<int> input = {5, 1, 4, 2};
    vector<int> actual = arrayOfProductsDS(input);
    return 0;
}