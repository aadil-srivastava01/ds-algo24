/* Problem Statement:

The distance between a node in a Binary Tree and the tree's root is called the node's depth.
Write a function that takes in a Binary Tree and returns the sum of its nodes' depths.
Each BinaryTree node has an integer value, a left child node, and a right child node.
Children nodes can either be BinaryTree nodes themselves or None / null

Solution Complexity:

Time: O(n) Time | Space: O(h) -> Tree height

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void traverseAndAddDepth(BinaryTree *ptr, int depth, int &sum)
{

    sum += depth;
    if ((ptr->left == NULL) and (ptr->right == NULL))
    {
        return;
    }

    if (ptr->left != NULL)
    {
        traverseAndAddDepth(ptr->left, depth + 1, sum);
    }
    if (ptr->right != NULL)
    {
        traverseAndAddDepth(ptr->right, depth + 1, sum);
    }
}

int nodeDepths(BinaryTree *root)
{
    // Write your code here.
    int depth{0};
    int sum{0};
    traverseAndAddDepth(root, depth, sum);
    return sum;
}

int main()
{

    return 0;
}