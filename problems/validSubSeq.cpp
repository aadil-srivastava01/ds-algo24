/* Problem Statement:

Validate Subsequence
Given two non-empty arrays of Integers, write a function that determines whether the second array is a subsequence of the first one.
A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are in the same order as they appear in the array. For instance, the numbers [1, 3, 4] form a subsequence of the array [1, 2, 3, 4], and so do the numbers [2, 4]. Note that a single number in an array and the array itself are both valid subsequences of the array.
Sample Input:
array = [5, 1, 22, 25, 6, -1, 8, 10] sequence = [1, 6, -1, 10]

Sample Output:
true

Solution Complexity:
O(n): Time & O(1): Space

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    size_t pointer1 = 0;
    size_t pointer2 = 0;
    size_t seqLen = sequence.size() - 1;

    while (pointer1 < array.size())
    {
        if (sequence.at(pointer2) == array.at(pointer1))
        {
            pointer1++;
            pointer2++;
        }
        else
        {
            pointer1++;
        }
        if (pointer2 > seqLen)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> array{5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> sequence{1, 6, -1, 10};
    cout << isValidSubsequence(array, sequence) << endl;
    return 0;
}