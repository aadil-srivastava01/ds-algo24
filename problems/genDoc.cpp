/* Problem Statement:
You're given a string of available characters and a string representing a document that you need to generate. Write a function that determines if you can generate the document using the available characters. If you can generate the document, your function should return true; otherwise, it should return false
You're only able to generate the document if the frequency of unique characters in the characters string is greater than or equal to the frequency of unique characters in the document string. For example, if you're given characters = "abcabc" and document = "aabbccc" you cannot generate the document because you're missing one c
The document that you need to create may contain any characters, including special characters, capital letters, numbers, and spaces.
Note: you can always generate the empty string ("")

Input: Characaters: abcabc, Document = aabbccc
Output: false

Solution Complexity:
generateDocument : Time: O(n + m) n & m are the lengh of 2 strings | Space: O(c1 + c2), number of unique chars in two strings
generateDocumentSpaceOptimsed: Time: O(n + m) n & m are the lengh of 2 strings | Space: O(c1), number of unique chars in characters string
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool generateDocument(string &characters, string &document)
{
    unordered_map<char, int> charCounter;
    unordered_map<char, int> docCounter;

    for (auto &c : characters)
    {
        charCounter[c] += 1;
    }
    for (auto &c : document)
    {
        docCounter[c] += 1;
    }

    for (auto iter = docCounter.begin(); iter != docCounter.end(); iter++)
    {
        if (charCounter.at(iter->first) >= iter->second)
            continue;
        return false;
    }
    return true;
}

bool generateDocumentSpaceOptimsed(string &characters, string &document)
{
    unordered_map<char, int> charCounter;

    for (auto &c : characters)
    {
        charCounter[c] += 1;
    }

    for (auto &c : document)
    {
        charCounter[c] -= 1;
        if (charCounter.at(c) < 0)
            return false;
    }
    return true;
}

int main()
{
    string document{"aabbccc"};
    string chars{"abcabc"};
    cout << generateDocument(chars, document) << endl;
    cout << generateDocumentSpaceOptimsed(chars, document) << endl;
    return 0;
}