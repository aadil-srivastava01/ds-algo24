/* Problem Statement:

Write a function that takes in a non-empty string and that returns a boolean representing whether the string is a palindrome.
A palindrome is defined as a string that's written the same forward and backward. Note that single-character strings are palindromes.
Sample Input
string "abcdcba"
Sample Output
true // it's written the same forward and backward

Solution Complexity:
Time: O(n) | Space: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string &str)
{
    if (str.empty())
        return false;

    int ptr1{0};
    int ptr2{static_cast<int>(str.size() - 1)};
    while (ptr1 <= ptr2)
    {
        if (str.at(ptr1) == str.at(ptr2))
        {
            ++ptr1;
            --ptr2;
            continue;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string input{"abcda"};
    cout << isPalindrome(input) << endl;
    return 0;
}