/* Problem Statement:
Write a function that takes in a list of unique strings and returns a list of semordnilap pairs.
A semordnilap pair is defined as a set of different strings where the reverse of one word is the same as the forward version of the other. For example the words "diaper" and "repaid" are a semordnilap pair, as are the words "palindromes" and "semordnilap".
The order of the returned pairs and the order of the strings within each pair does not matter.

Sample Input
words = ["diaper", "abc", "test", "cba", "repaid"]

Sample Output
[["diaper", "repaid"], ["abc", "cba"]]

Solution Complexity:
Time: O(n*m) | Space: O(n), where n = number of words in list, m = length of the longest word
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<string>> semordnilap(vector<string> words)
{
    unordered_set<string> tracker;
    vector<vector<string>> result;
    string temp;
    for (const auto &word : words)
    {
        reverse_copy(word.begin(), word.end(), std::back_inserter(temp));
        if (tracker.find(word) != tracker.end())
        {
            result.emplace_back(vector<string>{temp, word});
        }
        else
            tracker.emplace(temp);
        temp.clear();
    }
    return result;
}

int main()
{
    vector<string> input = {"desserts", "stressed", "hello"};
    vector<vector<string>> expected = {{"desserts", "stressed"}};
    auto actual = semordnilap(input);

    return 0;
}