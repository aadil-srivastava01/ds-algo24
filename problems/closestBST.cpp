/* Problem Statement:

Find Closest Value In BST
Write a function that takes in a Binary Search Tree (BST) and a target integer value and returns the closest value to that target value contained in the BST.
You can assume that there will only be one closest value.
Each BST node has an integer value, a left child node, and a right child node. A node is said to be a valid BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left; its value is less than or equal to the values of every node to its right; and its children nodes are either valld BST nodes themselves or None
null.


Solution Complexity:

O(logN): Time | O(1): Space
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdlib>

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target)
{
    // Write your code here.
    int min = INT_MAX;
    int minval;
    int tmp{0};
    while (tree != nullptr)
    {
        if (tree->value == target)
        {
            min = 0;
            return tree->value;
        }
        else if (tree->value > target)
        {
            tmp = abs((tree->value) - target);
            if (tmp < min)
            {
                min = tmp;
                minval = tree->value;
            }
            tree = tree->left;
        }
        else
        {
            tmp = abs((tree->value) - target);
            if (tmp < min)
            {
                min = tmp;
                minval = tree->value;
            }
            tree = tree->right;
        }
    }
    return minval;
}
