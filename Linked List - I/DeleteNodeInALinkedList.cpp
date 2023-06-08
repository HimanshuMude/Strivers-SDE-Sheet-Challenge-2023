#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    if (node == NULL)
        return;
    LinkedListNode<int> *temp = node;
    if (node->next == NULL)
    {
        node = NULL;
        return;
    }
    node->data = node->next->data;
    node = node->next;
    temp->next = node->next;
    delete (node);
}