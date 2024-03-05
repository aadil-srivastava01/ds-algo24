/* Problem Statement:

Write a function that takes in a non-empty array of Integers that are sorted in ascending order and returns a new array of the same length with the squares of the original integers also sorted in ascending order.
Sample Input
array = [1, 2, 3, 5, 6, 8, 9]
Sample Output
[1, 4, 9, 25, 36, 64, 81]

Solution Complexity:
O(n): Time & O(n): Space

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
    // Write your code here.
    int pointerFront = 0;
    int pointerBack = array.size() - 1;
    int arrPtr = array.size() - 1;
    vector<int> output(array.size());

    while (pointerFront <= pointerBack)
    {
        if (abs(array.at(pointerFront)) > abs(array.at(pointerBack)))
        {
            output.at(arrPtr) = array.at(pointerFront) * array.at(pointerFront);
            pointerFront++;
        }
        else
        {
            output.at(arrPtr) = array.at(pointerBack) * array.at(pointerBack);
            pointerBack--;
        }
        arrPtr--;
    }
    return output;
}

int main()
{
    vector<int> array{1, 2, 3, 5, 6, 8, 9};
    for (const auto &val : sortedSquaredArray(array))
        cout << val << endl;
    return 0;
}