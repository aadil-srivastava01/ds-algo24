/* Problem Statement:
Common Characters
Write a function that takes in a non-empty list of non-empty strings and returns a list of characters that are common to all strings In the list, Ignoring multiplicity.
Note that the strings are not guaranteed to only contain alphanumeric characters. The list you return can be in any order.
Sample Input
strings = ["abc", "bcd", "cbaccd"]
Sample Output
["b", "c"] // The characters could be ordered differently.

Solution Complexity:
Space: O(n)| Time: O(mxn) n-> number of strings m -> length of string
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
vector<string> commonCharacters(vector<string> strings)
{

    vector<string> result;

    if (strings.size() == 1)
        for (const auto character : strings)
            result.emplace_back(character);

    else
    {

        unordered_set<string> charTracker;
        unordered_map<string, int> counter;
        string temp;

        for (const auto &str : strings)
        {
            for (auto character : str)
            {
                temp += character;
                charTracker.emplace(temp);
                temp.clear();
            }
            for (auto itr = charTracker.begin(); itr != charTracker.end(); itr++)
            {
                cout << *itr << endl;
                counter[*itr] += 1;
            }
            charTracker.clear();
        }

        for (auto itr = counter.begin(); itr != counter.end(); itr++)
        {
            if (itr->second == strings.size())
                result.emplace_back(itr->first);
        }
    }
    return result;
}

int main()
{

    return 0;
}