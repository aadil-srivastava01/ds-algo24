/* Problem Statement:

Write a function that takes in a non-empty string and returns its run-length encoding.
From Wikipedia, "run-length encoding is a form of lossless data compression in which runs of data are stored as a single data value and count, rather than as the original run." For this problem, a run of data is any sequence of consecutive, Identical characters. So
the run "AAA" would be run-length-encoded as "3A"
To make things more complicated, however, the input string can contain all sorts of special characters, Including numbers. And since encoded data must be decodable, this means that we can't naively run-length-encode long runs. For example, the run "AAAAAAAAAAAA" (12 A s), can't naively be encoded as "12A", since this string can be decoded as either "AAAAAAAAAAAA" or "1AA". Thus, long runs (runs of 10 or more characters) should be encoded in a split fashion; the aforementioned run should be encoded as "9A3A"

Sample Input
string = "AAAAAAAAAAAAABBCCCCDD"
Sample Output
"9A4A2B4C2D"


Solution Complexity:

Time: O(n) | Space: O(n)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flushString(string &output, char prevChar, string count)
{
    output.append(count);
    output.push_back(prevChar);
    return;
}

string runLengthEncoding(string str)
{

    if (str.empty())
        return str;

    int counter{1};
    char prev{str.at(0)};
    string output;
    for (int i = 1; i < str.size(); i++)
    {
        if (str.at(i) == prev)
        {
            counter++;
        }
        if (counter == 9)
        {
            flushString(output, prev, to_string(9));
            counter = 0;
        }
        if (str.at(i) != prev)
        {
            if (counter > 0)
            {
                flushString(output, prev, to_string(counter));
            }
            counter = 1;
            prev = str.at(i);
        }
    }
    flushString(output, prev, to_string(counter));
    return output;
}

int main()
{
    string input{"AAAAAAAAAAAAABBCCCCDD"};
    cout << runLengthEncoding(input) << endl;
    return 0;
}