/* Problem Statement:

Implement Insertion Sort

Solution Complexity:

Time: Worst & Average n^2, best: n | Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = b;
    b = a;
    a = temp;
}

vector<int> insertionSort(vector<int> array)
{
    int lastIdx = array.size();
    for (int i = 1; i < lastIdx; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (array.at(j) > array.at(j + 1))
            {
                swap(array.at(j), array.at(j + 1));
                continue;
            }
            else
                break;
        }
    }
    return array;
}