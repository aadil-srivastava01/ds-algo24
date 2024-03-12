/* Problem Statement:

Write a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) whose absolute difference is closest to zero, and returns an array containing these two numbers, with the number from the first array in the first position.
Note that the absolute difference of two integers is the distance between them on the real number line. For example, the absolute difference of -5 and 5 is 10, and the absolute difference of -5 and -4 is 1.
You can assume that there will only be one pair of numbers with the smallest difference.
Sample Input
arrayOne = [-1, 5, 10, 20, 28, 3] arrayTwo = [26, 134, 135, 15, 17]
Sample Output
[28, 26]

Solution Complexity:

 Time: [O(nlogn) + O(mlogm)], m & n are array sizes | O(1) Space
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdlib>

using namespace std;

vector<int> smallestDifference(vector<int> &arrayOne, vector<int> &arrayTwo)
{

    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    auto ptr1{arrayOne.begin()};
    auto ptr2{arrayTwo.begin()};
    int diff{INT_MAX};
    int temp{0};
    int num1, num2 = 0;
    while (ptr1 != arrayOne.end() && ptr2 != arrayTwo.end())
    {
        temp = abs((*ptr1) - (*ptr2));
        if (temp < diff)
        {
            diff = temp;
            num1 = *ptr1;
            num2 = *ptr2;
        }
        if ((*ptr1) < (*ptr2))
        {
            if (ptr1 != arrayOne.end())
                ptr1++;
            else
                break;
        }
        else if (ptr2 != arrayTwo.end())
            ptr2++;
        else
            break;
    }
    return vector<int>{num1, num2};
}

int main()
{
    vector<int> array1{-1, 5, 10, 20, 28, 3};
    vector<int> array2{26, 134, 135, 15, 17};

    for (const int &num : smallestDifference(array1, array2))
    {
        cout << num << endl;
    }

    return 0;
}