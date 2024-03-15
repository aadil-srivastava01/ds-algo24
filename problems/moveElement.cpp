/* Problem Statement:

You're given an array of integers and an integer. Write a function that moves all instances of that integer in the array to the end of the array and returns the array.
The function should perform this in place (l.e., it should mutate the input array) and doesn't need to maintain the order of the other integers.
Sample Input
array = [2, 1, 2, 2, 2, 3, 4, 2] toMove = 2
Sample Output
[1, 3, 4, 2, 2, 2, 2, 2] // the numbers 1, 3, and 4 could be ordered differently

Solution Complexity:
Time: O(n) | Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> moveElementToEnd(vector<int> &array, int toMove)
{
    size_t ptr1{0};
    size_t ptr2{(array.size()) - 1};

    int noCounter{0};

    for (const int &item : array)
    {
        if (item != toMove)
        {
            array.at(ptr1) = item;
            ++ptr1;
        }
        else
        {
            noCounter++;
        }
    }
    while (noCounter >= 1)
    {
        array.at(ptr2) = toMove;
        --noCounter;
        --ptr2;
    }
    return array;
}

int main()
{

    vector<int> array{2, 1, 2, 2, 2, 3, 4, 2};
    moveElementToEnd(array, 2);
    return 0;
}