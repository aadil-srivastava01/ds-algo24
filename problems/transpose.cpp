/* Problem Statement:

Transpose Matrix
You're given a 2D array of integers matrix. Write a function that returns the transpose of the matrix.
The transpose of a matrix is a flipped version of the original matrix across its main diagonal (which runs from top-left to bottom- right); it switches the row and column indices of the original matrix.
You can assume the input matrix always has at least 1 value; however its width and height are not necessarily the same.
Sample Input #1
matrix = [ [1, 2], ]
Sample Output #1
[ [1],
  [2]
]

Solution Complexity:
Time: O(m*n) | Space O(m*n), m & n are width and height of matrix
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix)
{
    size_t width = matrix.at(0).size();
    size_t height = matrix.size();

    vector<vector<int>> transpose(width, vector<int>(height));
    for (size_t row{0}; row < height; row++)
    {
        for (size_t column{0}; column < width; column++)
        {
            transpose.at(column).at(row) = matrix.at(row).at(column);
        }
    }
    return transpose;
}

int main()
{
    vector<vector<int>> matrix(2, vector<int>{1});
    matrix.at(1) = vector<int>{-1};
    auto result = transposeMatrix(matrix);
    for (auto &row : result)
    {
        for (int &item : row)
            cout << item << endl;
        cout << endl;
    }
    return 0;
}