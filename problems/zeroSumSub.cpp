/* Problem Statement:

Zero Sum Subarray
You're given a list of integers nums. Write a function that returns a boolean representing whether there exists a zero-sum subarray of nums
A zero-sum subarray is any subarray where all of the values add up to zero. A subarray is any contiguous section of the array. For the purposes of this problem, a subarray can be as small as one element and as long as the original array.
Sample Input
nums = [-5, -5, 2, 3, -2]
Sample Output
True // The subarray [-5, 2, 3] has a sum of o


Solution Complexity:
Time: O(n) | Space: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool zeroSumSubarray(vector<int> nums)
{
    if (nums.size() > 0)
    {
        unordered_set<int> preSum;
        int sum{0};
        preSum.emplace(sum);
        for (size_t i = 1; i <= nums.size(); i++)
        {
            if (nums.at(i - 1) == 0)
                return true;
            else
            {
                sum += nums.at(i - 1);
                if (preSum.find(sum) != preSum.end())
                {
                    return true;
                }
                else
                {
                    preSum.emplace(sum);
                }
            }
        }
    }
    return false;
}

int main()
{
    auto input = {4, 2, -1, -1, 3};
    cout << zeroSumSubarray(input);
    return 0;
}