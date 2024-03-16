/* Problem Statement:

returns a modified version of the Linked List that doesn't contain any nodes with duplicate values. The Linked List should be modified in place (I.e., you shouldn't create a brand new list), and the modified Linked List should still have its nodes sorted with respect to their values.
Each LinkedList node has an Integer value as well as a next node pointing to the next node in the list or to None / null if it's the tail of the list.
Sample Input
linkedList = 1 -> 1 -> 3 -> 4 -> 4 -> 4 -> 5 -> 6 -> 6// the head node with value 1
Sample Output
1 -> 3 -> 4 -> 5 ->6 // the head node with value

Solution Complexity:
Time: O(n) | Space O(1)
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

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList)
{

    auto curr = linkedList;
    while ((curr->next) != NULL)
    {
        if ((curr->value) == ((curr->next)->value))
        {
            (curr->next) = ((curr->next)->next);
            continue;
        }
        else
            curr = curr->next;
    }
    return linkedList;
}
