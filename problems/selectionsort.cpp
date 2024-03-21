/* Problem Statement:

Perform Selection Sort

Solution Complexity:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <vector>
#include <limits.h>
using namespace std;

vector<int> selectionSort(vector<int> array)
{

    int minIdx{0};
    int minVal{INT_MAX};
    bool flag{false};
    for (int i{0}; i < array.size(); i++)
    {
        minIdx = 0;
        minVal = INT_MAX;
        flag = false;

        for (int j = i + 1; j < array.size(); j++)
        {
            if (array.at(j) < minVal)
            {
                minVal = array.at(j);
                minIdx = j;
            }
            flag = true;
        }
        if (flag)
        {
            cout << minVal << endl;
            array.at(minIdx) = array.at(i) + array.at(minIdx);
            array.at(i) = array.at(minIdx) - array.at(i);
            array.at(minIdx) = array.at(minIdx) - array.at(i);
        }
    }
    return array;
}

int main()
{

    return 0;
}