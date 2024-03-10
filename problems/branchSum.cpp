/* Problem Statement:

Write a function that takes in a Binary Tree and returns a list of its branch sums ordered from leftmost branch sum to rightmost
branch sum.
A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree branch is a path of nodes in a tree that starts at the root node and ends at any leaf node.
Each BinaryTree node has an Integer value, a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or None / null

Solution Complexity:

Time: O(n) | Space O(n)
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

void traverseAndSum(BinaryTree *ptr, int sum, vector<int> &result)
{

    int curr{sum + (ptr->value)};
    if ((ptr->left == NULL) and (ptr->right == NULL))
    {
        result.emplace_back(curr);
        return;
    }
    if (ptr->left != NULL)
        traverseAndSum(ptr->left, curr, result);
    if (ptr->right != NULL)
        traverseAndSum(ptr->right, curr, result);
}

vector<int> branchSums(BinaryTree *root)
{
    int sum{0};
    BinaryTree *ptr{root};
    vector<int> result;
    traverseAndSum(ptr, sum, result);
    return result;
}
