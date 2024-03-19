/* Problem Statement:

Write Bubble Sort

Solution Complexity:

O(n^2) Time | O(1) Space

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bubbleSort(vector<int> array)
{
    int size = static_cast<int>(array.size());
    int lastIndex{0};
    for (int i = 0; i < size; i++)
    {
        lastIndex = size - i - 1;
        for (int j = 0; j < lastIndex; j++)
        {
            if (array.at(j) > array.at(j + 1))
            {
                swap(array.at(j), array.at(j + 1));
            }
            continue;
        }
    }
    return array;
}

void swap(int &a, int &b)
{
    b = a + b;
    a = b - a;
    b = b - a;
    return;
}

int main()
{

    return 0;
}