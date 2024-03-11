/* Problem Statement:

You're given a binary expression tree. Write a function to evaluate this tree mathematically and return a single resulting integer.
All leaf nodes in the tree represent operands, which will always be positive Integers. All of the other nodes represent operators. There are 4 operators supported, each of which is represented by a negative integer:
-1: Addition operator, adding the left and right subtrees.
-2: Subtraction operator, subtracting the right subtree from the left subtree.
-3: Division operator, dividing the left subtree by the right subtree. If the result is a decimal, it should be rounded towards zero.
-4: Multiplication operator, multiplying the left and right subtrees.
You can assume the tree will always be a valid expression tree. Each operator also works as a grouping symbol, meaning the bottom of the tree is always evaluated first, regardless of the operator.

Solution Complexity:

Time: O(n) | Space: O(h), h -> Tree Height

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int preOrderTraverse(BinaryTree *ptr)
{
    if ((ptr->left == NULL) && (ptr->right == NULL))
        return ptr->value;
    int leftOperand = preOrderTraverse(ptr->left);
    int rightOperand = preOrderTraverse(ptr->right);

    switch (ptr->value)
    {
    case -1:
        return (leftOperand + rightOperand);
    case -2:
        return (leftOperand - rightOperand);
    case -3:
        return (leftOperand / rightOperand);
    case -4:
        return (leftOperand * rightOperand);
    default:
        return 0;
    }
}

int evaluateExpressionTree(BinaryTree *tree)
{
    return preOrderTraverse(tree);
}