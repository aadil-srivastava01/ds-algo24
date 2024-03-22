/* Problem Statement:

Perform Selection Sort

Solution Complexity:
Time: O(n^2) | Space: O(1)
*/

#include <vector>
#include <limits.h>
using namespace std;

vector<int> selectionSort(vector<int> array)
{

    int minIdx{0};
    int minVal{INT_MAX};
    int temp;
    bool flag{false};
    for (int i{0}; i < array.size(); i++)
    {
        minIdx = 0;
        minVal = INT_MAX;

        for (int j = i; j < array.size(); j++)
        {
            if (array.at(j) < minVal)
            {
                minVal = array.at(j);
                minIdx = j;
            }
        }
        temp = array.at(i);
        array.at(i) = array.at(minIdx);
        array.at(minIdx) = temp;
    }
    return array;
}