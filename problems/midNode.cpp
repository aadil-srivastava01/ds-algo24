/* Problem Statement:
You're given a Linked List with at least one node. Write a function that returns the middle node of the Linked List. If there are two middle nodes (i.e. an even length list), your function should return the second of these nodes.
Each LinkedList node has an integer value as well as a next node pointing to the next node in the list or to None /
null if it's the tail of the list.
Sample Input
linkedList = 2 -> 7 -> 3> 5
Sample Output
// The middle could be 7 or 3,
3 -> 5 // we return the second middle node


Solution Complexity:
Time: O(n) | Space : O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *middleNode(LinkedList *linkedList)
{
    size_t nodeCounter{0};
    auto curr{linkedList};
    while (curr != NULL)
    {
        ++nodeCounter;
        curr = (curr->next);
    }
    size_t midElem{nodeCounter / 2};
    nodeCounter = 0;
    curr = linkedList;
    while (curr != NULL)
    {
        if (nodeCounter == midElem)
            return curr;
        else
        {
            curr = curr->next;
            ++nodeCounter;
        }
    }
    return nullptr;
}

int main()
{

    return 0;
}