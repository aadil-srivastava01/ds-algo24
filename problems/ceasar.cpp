/* Problem Statement:

Caesar Cipher Encryptor
Given a non-empty string of lowercase letters and a non-negative Integer representing a key, write a function that returns a new
string obtained by shifting every letter in the input string by k positions in the alphabet, where k is the key.
Note that letters should "wrap" around the alphabet; in other words, the letter z shifted by one returns the letter a
Sample Input
string = "xyz"
key = 2
Sample Output
"zab"

Solution Complexity:
Time : O(n) | Space: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string caesarCypherEncryptor(string str, int key)
{

    int rotationFactor{key % 26};
    for (auto &c : str)
    {
        c -= 97;
        c += rotationFactor;
        c = (c % 26) + 97;
    }
    return str;
}

int main()
{

    string input{"abcda"};
    cout << caesarCypherEncryptor(input, 400) << endl;
    return 0;
}