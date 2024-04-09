/* Problem Statement:

You walk into a theatre you're about to see a show in. The usher within the theatre walks you to your row and mentions you're allowed to sit anywhere within the given row. Naturally you'd like to sit in the seat that gives you the most space. You also would prefer this space to be evenly distributed on either side of you (e.g. If there are three empty seats in a row, you would prefer to sit In the middle of those three seats).
Given the theatre row represented as an Integer array, return the seat index of where you should sit. Ones represent occupied seats and zeroes represent empty seats.
You may assume that someone is always sitting in the first and last seat of the row. Whenever there are two equally good seats, you should sit in the seat with the lower index. If there is no seat to sit in, return -1. The given array will always have a length of at least one and contain only ones and zeroes.
Sample Input
seats [1, 0, 1, 0, 0, 0, 1]
Sample Output
4

Solution Complexity:

Time: O(n) | Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bestSeat(vector<int> array)
{
    bool seenZero{false};
    bool wasSeatEmpty{false};

    int maxCount{0};
    int currCount{0};
    int maxStartIdx{0};
    int maxEndidx{0};
    int temp{0};

    for (int idx = 0; idx < array.size(); idx++)
    {
        if (!seenZero && array.at(idx) == 0)
        {
            seenZero = true;
            currCount++;
            temp = idx;
            wasSeatEmpty = true;
            continue;
        }
        else if (seenZero && array.at(idx) == 0)
        {
            currCount++;
            seenZero = true;
            continue;
        }
        else if (seenZero && array.at(idx) == 1)
        {
            if (maxCount < currCount)
            {
                maxStartIdx = temp;
                maxEndidx = idx - 1;
                maxCount = currCount;
            }
            currCount = 0;
            seenZero = false;
            temp = 0;
            continue;
        }
        else if (!seenZero && array.at(idx) == 1)
        {
            continue;
        }
    }
    if (wasSeatEmpty)
        return (maxStartIdx + maxEndidx) / 2;
    else
        return -1;
}

int main()
{
    vector<int> input = {1, 0, 1, 0, 0, 0, 1};
    cout << bestSeat(input) << endl;
    return 0;
}