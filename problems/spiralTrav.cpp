/* Problem Statement:

Write a function that takes in an n x m two-dimensional array (that can be square-shaped when n m) and returns a one- dimensional array of all the array's elements in spiral order.
Spiral order starts at the top left corner of the two-dimensional array, goes to the right, and proceeds in a spiral pattern all the way until every element has been visited.
Sample Input
array = [
[1, 2, 3, 4],
[12, 13, 14, 5],
[11, 16, 15, 6],
[10, 9, 8, 7],
]
Sample Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]

Solution Complexity:

Time: O(m x n) | Space: O(n x m) -> n & m are matrix dimensions
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void prameterTraversal(const vector<vector<int>> &array,
                       vector<int> &output,
                       int startRow,
                       int endRow,
                       int startCol,
                       int endCol)
{
    int colTraveler{startCol};
    int rowTraveler{startRow};
    while (true)
    {
        if (colTraveler <= endCol)
        {
            output.emplace_back(array.at(rowTraveler).at(colTraveler));
            colTraveler++;
            continue;
        }
        else
            break;
    }
    colTraveler--;
    rowTraveler++;

    while (true)
    {
        if (rowTraveler <= endRow)
        {
            output.emplace_back(array.at(rowTraveler).at(colTraveler));
            rowTraveler++;
            continue;
        }
        else
            break;
    }
    rowTraveler--;
    colTraveler--;

    while (true)
    {
        if (colTraveler >= startCol && startRow != endRow)
        {
            output.emplace_back(array.at(rowTraveler).at(colTraveler));
            colTraveler--;
            continue;
        }
        else
            break;
    }
    colTraveler++;
    rowTraveler--;

    while (true)
    {
        if (rowTraveler > startRow && endCol != startCol)
        {
            output.emplace_back(array.at(rowTraveler).at(colTraveler));
            rowTraveler--;
            continue;
        }
        else
            break;
    }
}

vector<int> spiralTraverse(vector<vector<int>> array)
{
    int startRow{0};
    int endRow{static_cast<int>(array.size() - 1)};
    int startCol{0};
    int endCol{static_cast<int>(array.at(0).size() - 1)};
    vector<int> output;

    while ((startRow <= endRow) && (startCol <= endCol))
    {
        prameterTraversal(array, output, startRow, endRow, startCol, endCol);
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
    return output;
}

int main()
{

    return 0;
}