/* Problem Statement:

Write an algorithm to determine if the target integer is contained in the array and should return its index if it is, otherwise -1
If you're unfamiliar with Binary Search, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.
Sample Input
array = [0, 1, 21, 33, 45, 45, 61, 71, 72, 73] target = 33
Sample Output
3

Solution Complexity:

Time: O(logn) | Space: O(1) -> Using Tail Recursion

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bSearch(const vector<int> &array, int &target, int bottom, int up)
{
    if ((bottom == up) && (array.at(up) != target))
        return -1;

    int mid{(bottom + up) / 2};
    if (array.at(mid) == target)
    {
        return mid;
    }
    else if (array.at(mid) > target)
    {
        return bSearch(array, target, bottom, mid - 1);
    }
    else
        return bSearch(array, target, mid + 1, up);
}

int binarySearch(vector<int> &array, int target)
{
    return bSearch(array, target, 0, array.size() - 1);
}

int main()
{
    vector<int> array{0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
    cout << binarySearch(array, 33);
    return 0;
}