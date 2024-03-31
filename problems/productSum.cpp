/* Problem Statement:

Write a function that takes in a "special" array and returns its product sum.
A "special" array is a non-empty array that contains either integers or other "special" arrays. The product sum of a "special" array is the sum of its elements, where "special" arrays Inside it are summed themselves and then multiplied by their level of depth.
The depth of a "special" array is how far nested it is. For instance, the depth of [] is 1; the depth of the inner array in [[]] Is 2; the depth of the innermost array in [[[]]] is 3
Therefore, the product sum of [x, y] is x + y; the product sum of [x, [y, z]] Is x + 2*(y+z); the product sum of [x, [y, [z]]] Is x + 2* (y + 3z)

Sample Input
array [5, 2, [7, 1], 3, [6, [-13, 8], 4]]

Sample Output
12 // calculated as: 5+2+2 (71)+3+2 (6+ 3 (-13+8) 4)


Solution Complexity:
Time: O(n) | O(d), n-> Total number of elements including sub array's element, d -> maximum depth
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <any>

using namespace std;

int depthSum(int depth, vector<any> &array)
{
    int sum{0};
    for (const auto &elem : array)
    {
        if (elem.type() == typeid(vector<any>))
        {
            vector<any> temp = any_cast<vector<any>>(elem);
            sum += depthSum(depth + 1, temp);
        }
        else if (elem.type() == typeid(int))
            sum += any_cast<int>(elem);
    }
    return (depth * sum);
}
int productSum(vector<any> array)
{
    return depthSum(1, array);
}

int main()
{
    vector<any> test = {
        5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};

    cout << productSum(test);
    return 0;
}