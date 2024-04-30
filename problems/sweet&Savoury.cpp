/* Problem Statement:

complement each other's flavor profile.
Each dish has a flavor profile represented by an Integer. A negative Integer means a dish is sweet, while a positive Integer means a dish is savory. The absolute value of that Integer represents the Intensity of that flavor. For example, a flavor profile of -3 is slightly sweet, one of -10 is extremely sweet, one of 2 is mildly savory, and one of 8 is significantly savory.
You're given an array of these dishes and a target combined flavor profile. Write a function that returns the best possible pairing of two dishes (the pairing with a total flavor profile that's closest to the target one). Note that this pairing must include one sweet and one savory dish. You're also concerned about the dish being too savory, so your pairing should never be more savory than the target flavor profile.
All dishes will have a positive or negative flavor profile; there are no dishes with a 0 value. For simplicity, you can assume that there will be at most one best solution. If there isn't a valid solution, your function should return [0, 0]. The returned array should be sorted, meaning the sweet dish should always come first.
Sample Input #1
dishes [3, 5, 1, 7]
target = 8
Sample Output #1
[-3, 7] // The combined profile of 4 is closest without going over
Sample Input #2
dishes = [3, 5, 7, 2, 6, 8, 1] target = 10
Sample Output #2
[0, 0] // There are no sweet dishes
Sample Input #3
dishes = [2, 5, 4, 7, 12, 100, -25] target = -20
Sample Output #3
[-25, 5] // This pairing gets the exact combined profile of -20

Solution Complexity:
Time: O(n(log(n))) | Space: O(1)
*/

#include <algorithm>
#include <limits.h>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target)
{

    size_t ptr1{0};
    size_t ptr2{dishes.size() - 1};
    int tempDiff{0};
    int minDiff{INT_MAX};

    std::vector<int> result(2);

    if (dishes.size() > 0)

    {
        std::sort(dishes.begin(), dishes.end());

        while (ptr1 < ptr2)
        {
            if ((dishes.at(ptr1) > 0 && dishes.at(ptr2) > 0) || (dishes.at(ptr1) < 0 && dishes.at(ptr2) < 0))
            {
                break;
            }
            else
            {
                tempDiff = std::abs(target - (dishes.at(ptr1) + dishes.at(ptr2)));
                if ((tempDiff < minDiff) && ((dishes.at(ptr1) + dishes.at(ptr2)) <= target))
                {
                    result.at(0) = dishes.at(ptr1);
                    result.at(1) = dishes.at(ptr2);
                    minDiff = tempDiff;
                }

                if ((std::abs(target - (dishes.at(ptr1) + dishes.at(ptr2 - 1)))) > (std::abs(target - (dishes.at(ptr1 + 1) + dishes.at(ptr2)))))
                    ptr1++;
                else
                    ptr2--;
            }
        }
    }
    return result;
}
