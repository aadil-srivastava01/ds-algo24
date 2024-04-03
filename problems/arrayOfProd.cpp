/* Problem Statement:
Write a function that takes in a non-empty array of integers and returns an array of the same length, where each element in the output array is equal to the product of every other number in the input array.
In other words, the value at output [i] is equal to the product of every number in the input array other than input[i] Note that you're expected to solve this problem without using division.
Sample Input
array [5, 1, 4, 2]
Sample Output
[8, 40, 10, 20]
// 8 is equal to 1 x 4 x 2
// 40 is equal to 5 x 4 x 2
// 10 is equal to 5 x 1 x 2
// 20 is equal to 5 x 1 x 4

Solution Complexity:

*/

#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{

    return 0;
}