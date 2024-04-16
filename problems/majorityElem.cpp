/* Problem Statement:
Write a function that takes in a non-empty, unordered array of positive integers and returns the array's majority element without sorting the array and without using more than constant space.
An array's majority element is an element of the array that appears in over half of its indices. Note that the most common element of an array (the element that appears the most times in the array) isn't necessarily the array's majority element; for example, the arrays [3, 2, 2, 1] and [3, 4, 2, 2, 1] both have 2 as their most common element, yet neither of these arrays have a majority element, because neither 2 nor any other element appears in over half of the respective arrays' Indices.
You can assume that the input array will always have a majority element.
Sample Input
array = [1, 2, 3, 2, 2, 1, 2]
Sample Output
2 // 2 occurs in 4/7 array indices, making it the majority element


Solution Complexity:

Time: O(n) | Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> array)
{
    // Write your code here.
    int counter{0};
    int majorityElem{array.at(0)};

    for (size_t i = 1; i < array.size(); i++)
    {
        if (array.at(i) == majorityElem)
        {
            counter++;
            continue;
        }
        if (counter > 0 && (array.at(i) != majorityElem))
        {
            counter--;
            continue;
        }
        else if (counter == 0 && (array.at(i) != majorityElem))
        {
            majorityElem = array.at(i);
            continue;
        }
    }
    return majorityElem;
}

int main()
{
    vector<int> input = {1, 2, 3, 2, 2, 1, 2};
    cout << majorityElement(input) << endl;
    return 0;
}