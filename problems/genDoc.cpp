/* Problem Statement:
You're given a string of available characters and a string representing a document that you need to generate. Write a function that determines if you can generate the document using the available characters. If you can generate the document, your function should return true; otherwise, it should return false
You're only able to generate the document if the frequency of unique characters in the characters string is greater than or equal to the frequency of unique characters in the document string. For example, if you're given characters = "abcabc" and document = "aabbccc" you cannot generate the document because you're missing one c
The document that you need to create may contain any characters, including special characters, capital letters, numbers, and spaces.
Note: you can always generate the empty string ("")


Solution Complexity:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool generateDocument(string characters, string document)
{
    unordered_map<char, int> charCounter;
    unordered_map<char, int> docCounter;

    for (auto &c : characters)
    {
        charCounter[c] += 1;
    }
    for (auto &c : document)
    {
        document[c] += 1;
    }

    for (auto iter = docCounter.begin(); iter != docCounter.end(); iter++)
    {
        cout << iter->first;
        // if(charCounter.at(iter-> first) == iter ->second)
        //   continue;
        // else
        //   return false;
    }
    return true;
}

int main()
{

    return 0;
}