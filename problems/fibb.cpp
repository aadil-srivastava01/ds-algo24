/* Problem Statement:

The Fibonacci sequence is defined as follows: the first number of the sequence is, the second number is 1, and the nth number is the sum of the (n - 1)th and (n-2)th numbers. Write a function that takes in an integer n and returns the nth Fibonacci number.
Important note: the Fibonacci sequence is often defined with its first two numbers as Fo 0 and F1 = 1. For the purpose of this question, the first Fibonacci number is F0; therefore, getNthFib (1) is equal to Fo getNthFib(2) Is equal to F1 etc..
Sample Input #1
2
Sample Output #1
1 //0, 1


Solution Complexity:
Time: O(n) || Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getNthFib(int n)
{
    int prev = 0;
    int prevPre = 1;
    int fibb{0};

    switch (n)
    {
    case 1:
        return prev;
    case 2:
        return prevPre;
    default:
    {
        for (int i{2}; i <= n; ++i)
        {
            fibb = {prev + prevPre};
            prevPre = prev;
            prev = fibb;
        }
        return fibb;
    }
    }
}

int main()
{
    cout << getNthFib(20) << endl;
    return 0;
}