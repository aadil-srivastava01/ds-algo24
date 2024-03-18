/* Problem Statement:

The function should return duplicate integers if necessary; for example, it should return [10, 10, 12] for an Input array of [10, 5, 9, 10, 12]
Sample Input
array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
Sample Output
[18, 141, 541]
Solution Complexity:
Time: O(n) | Space: O(1)
*/

#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> &array)
{
    vector<int> threeNo{INT_MIN, INT_MIN, INT_MIN};
    for (const int &num : array)
    {
        if (num > threeNo.at(2))
        {
            threeNo.at(0) = threeNo.at(1);
            threeNo.at(1) = threeNo.at(2);
            threeNo.at(2) = num;
        }
        else if (num > threeNo.at(1))
        {
            threeNo.at(0) = threeNo.at(1);
            threeNo.at(1) = num;
        }
        else if (num > threeNo.at(0))
            threeNo.at(0) = num;
    }
    return threeNo;
}

int main()
{
    vector<int> array{141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    for (const int &num : findThreeLargestNumbers(array))
    {
        cout << num << endl;
    }
    return 0;
}