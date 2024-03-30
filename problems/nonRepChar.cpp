/* Problem Statement:

First Non-Repeating Character
Write a function that takes in a string of lowercase English-alphabet letters and returns the index of the string's first non-repeating character.
The first non-repeating character is the first character in a string that occurs only once.
If the Input string doesn't have any non-repeating characters, your function should return -1
Sample Input
string = "abcdcaf"
Sample Output
1// The first non-repeating character is "b" and is found at index 1.

Solution Complexity:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int firstNonRepeatingCharacter(string string)
{
    array<int, 26> alphaTrack = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (const auto &c : string)
    {
        alphaTrack.at(static_cast<int>(c) - 97) += 1;
    }
    size_t idx{0};
    for (const auto &c : string)
    {
        if (alphaTrack.at(static_cast<int>(c) - 97) == 1)
            return idx;
        idx++;
    }
    return -1;
}

int main()
{

    cout << firstNonRepeatingCharacter("abcdcaf") << endl;
    return 0;
}