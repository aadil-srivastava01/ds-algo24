/* Problem Statement:

You're given a Node class that has a name and an array of optional children nodes. When put together, nodes form an acyclic tree-like structure.
Implement the depthFirstSearch method on the Node class, which takes in an empty array, traverses the tree using the Depth-first Search approach (specifically navigating the tree from left to right), stores all of the nodes' names in the input array, and returns it.
If you're unfamiliar with Depth-first Search, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

Solution Complexity:
Time: O(n) | Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector<string> depthFirstSearch(vector<string> *array)
    {
        (*array).emplace_back(name);
        for (const auto &node : children)
            traverse(node, *array);
        return *array;
    }

    void traverse(Node *ptr, vector<string> &array)
    {
        array.emplace_back(ptr->name);
        for (const auto &node : ptr->children)
        {
            traverse(node, array);
        }
        return;
    }

    Node *addChild(string name)
    {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
