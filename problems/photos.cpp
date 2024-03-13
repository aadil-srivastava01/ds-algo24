/* Problem Statement:

It's photo day at the local school, and you're the photographer assigned to take class photos. The class that you'll be photographing has an even number of students, and all these students are wearing red or blue shirts. In fact, exactly half of the class is wearing red shirts, and the other half Is wearing blue shirts. You're responsible for arranging the students in two rows before taking the photo. Each row should contain the same number of the students and should adhere to the following guidelines:
• All students wearing red shirts must be in the same row.
• All students wearing blue shirts must be in the same row.
• Each student in the back row must be strictly taller than the student directly in front of them In the front row.
You're given two input arrays: one containing the heights of all the students with red shirts and another one containing the heights of all the students with blue shirts. These arrays will always have the same length, and each height will be a positive Integer. Write a function that returns whether or not a class photo that follows the stated guidelines can be taken.
Note: you can assume that each class has at least 2 students.
Sample Input
redShirtHeights = [5, 8, 1, 3, 4] blueShirtHeights = [6, 9, 2, 4, 5]
Sample Output
true

Solution Complexity:
Time: O(nlogn) | Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool classPhotos(vector<int> &redShirtHeights, vector<int> &blueShirtHeights)
{
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort(blueShirtHeights.begin(), blueShirtHeights.end());

    bool isBlueTall = blueShirtHeights.at(0) > redShirtHeights.at(0) ? true : false;

    for (size_t idx{0}; idx < blueShirtHeights.size(); idx++)
    {
        if (isBlueTall && (blueShirtHeights.at(idx) <= redShirtHeights.at(idx)))
            return false;
        else if (!isBlueTall && (blueShirtHeights.at(idx) >= redShirtHeights.at(idx)))
            return false;
        else
            continue;
    }
    return true;
}

int main()
{
    vector<int> a{5, 8, 1, 3, 4};
    vector<int> b{6, 9, 2, 4, 5};
    cout << classPhotos(a, b) << endl;
    return 0;
}